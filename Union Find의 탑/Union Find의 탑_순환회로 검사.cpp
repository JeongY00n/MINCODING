#include <iostream>
#include<stdlib.h>
#include<queue>
using namespace std;


int parents[1001];

int Find(int now) {
	if (now == parents[now])
		return now;
	return parents[now] = Find(parents[now]);

}
void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parents[pB] = pA;
}
int main() {

	int n;
	int map[1001][1001];
	cin >> n;

	for (int i = 0; i < n; i++)
		parents[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	// 이차원 배열로 입력 받았기 때문에 중복이 존재하므로
	// i부터 n까지의 열에 대해서만 본다
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			if (map[i][j] == 0)continue;
			if (Find(i) == Find(j)) {
				cout << "WARNING";
				return 0;
			}

			Union(i, j);
		}
	}


	cout << "STABLE";
	return 0;
}