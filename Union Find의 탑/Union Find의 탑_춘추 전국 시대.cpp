#include <iostream>
#include<stdlib.h>
#include<queue>
using namespace std;


struct Edge {
	string state;
	char from;
	char to;
};

vector<Edge> v;
char parents[91];
int cost[91];
int country[91];

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

	cost[pA] += cost[pB];
	cost[pB] = 0;

	country[pA] += country[pB];
	country[pB] = 0;

}

// ��� ������ ������ ���ͱ��� ���ϴ��� (country)
// ������ �������� �α���(cost)

int main() {

	int n;
	cin >> n;
	
	for (char a = 'A'; a < 'A'+n; a++)
	{
		parents[a] = a;
		cin >> cost[a];
		country[a] = 1;
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		char from, to;
		string state;
		cin >> state >> from >> to;
		v.push_back({ state, from, to });
	}

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		string state = v[i].state;
		char from = v[i].from;
		char to = v[i].to;

		char pfrom = Find(from);
		char pto = Find(to);

		if (pfrom == pto)continue;

		if (state == "war") {

			//from, to�� cost�� ���ϴ� ���� �ƴ϶� 
			//���ͱ��� ��ǥ ������ ���� �� �α� ���� ���ؾ��ϹǷ�
			//pfrom, pto�� ���


			if (cost[pfrom] > cost[pto]) {
				char lose = Find(to);
				cnt += country[lose];
				country[lose] = 0;
				cost[lose] = 0;
			}
			else if(cost[pfrom] < cost[pto]) {
				char lose = Find(from);
				cnt += country[lose];
				country[lose] = 0;
				cost[lose] = 0;
			}
			else {
				char lose1 = Find(from);
				cnt += country[lose1];
				country[lose1] = 0;
				cost[lose1] = 0;

				char lose2 = Find(to);
				cnt += country[lose2];
				country[lose2] = 0;
				cost[lose2] = 0;
			}
		}
		else {
			Union(from, to);
		}

			
	}
	cout << n - cnt;

	return 0;
}