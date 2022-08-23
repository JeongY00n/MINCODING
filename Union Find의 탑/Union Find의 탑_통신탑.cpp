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
		//cnt �ʱ�ȭ
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
		// ������ ����� ���� (�׷��� �� ������ �� - 1): 4������ �ϳ��� �δ��� cnt => 3
		// �δ��� ������ Ȯ���ؾ��ϹǷ� n - cnt�� ���ָ� �ȴ�
		cout << n - cnt << endl;

		group.clear();
	}
	return 0;
}