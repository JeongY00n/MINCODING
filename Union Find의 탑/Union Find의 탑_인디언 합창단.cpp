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

// ��ǥ ��忡 ����� ������ ������ ���ش�
// 'A'���� 'Z'�� ���� ���� ��忡 ���� count�� ���ְ� Union���� ����� ���ش�
// ��ǥ ��尡 �����Ǹ� ��ǥ ��忡 ������ groupcnt������ �߰��ϰ�
// ������ 0���� �Ѵ�
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