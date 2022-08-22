#include <iostream>
#include<stdlib.h>
#include<queue>
using namespace std;


struct Edge {
	char from;
	char to;
};

vector<Edge> edge;
char parents[92];
int GroupCnt[92];
char Find(char now) {
	if (now == parents[now])
		return now;
	return parents[now] = Find(parents[now]);
}

void Union(char A, char B) {

	char pA = Find(A);
	char pB = Find(B);

	if (pA == pB)return;

	parents[pB] = pA;

	GroupCnt[pA] += GroupCnt[pB];
	GroupCnt[pB] = 0;

}

// 대표 노드에 연결된 간선의 갯수를 세준다
// 'A'부터 'Z'에 먼저 본인 노드에 대한 count를 해주고 Union에서 계산을 해준다
// 대표 노드가 결정되면 대표 노드에 본인의 groupcnt갯수를 추가하고
// 본인은 0으로 한다
int main() {

	int n;
	cin >> n;
	
	for (char a = 'A'; a <= 'Z'; a++)
	{
		parents[a] = a;
		GroupCnt[a] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		char n1, n2;
		cin >> n1 >> n2;
		edge.push_back({ n1,n2 });
	}
	int cnt = 0;
	for (int i = 0; i < edge.size(); i++) {
		char from = edge[i].from;
		char to = edge[i].to;

		if (Find(from) == Find(to)) continue;

		Union(from, to);

	}
	int team=0;
	int nosolo=0;
	for (char a = 'A'; a <= 'Z'; a++){
		
		if (GroupCnt[a] > 1)
		{
			team++;
			nosolo += GroupCnt[a];
		}
	}
	cout << team << "\n" << 26 - nosolo;
	
	
	return 0;
}