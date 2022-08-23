#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node {
	int y, x;
	int R;
};

int parents[3001];
vector<Node> group;
int cnt = 0;

int Find(int now) {
	if (now == parents[now])
		return now;
	return parents[now] = Find(parents[now]);

}
void Union(int a, int b) {

	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)return;

	Node A = group[a];
	Node B = group[b];

	int dist = (A.y - B.y) * (A.y - B.y) + (A.x - B.x) * (A.x - B.x);
	
	if (dist > (A.R + B.R) * (A.R + B.R))
		return;
	
	cnt++;
	parents[pb] = pa;

}

int main() {

	int T;
	cin >> T;
	
	
	for (int test_case = 1; test_case <= T; test_case++){

		int n;
		cin >> n;
		//cnt 초기화
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int y, x, R;
			cin >> y >> x >> R;
			group.push_back({ y,x,R });
			
			parents[i] = i;
		}

		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (Find(i) == Find(j))
					continue;
			
				Union(i, j);
			}
		}
		// 위에서 계산한 값은 (그룹이 된 적군의 수 - 1): 4진영이 하나의 부대라면 cnt => 3
		// 부대의 개수를 확인해야하므로 n - cnt를 해주면 된다
		cout << n - cnt << endl;

		group.clear();
	}
	return 0;
}