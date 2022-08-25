#include <iostream>
#include<stdlib.h>
#include<unordered_map>
using namespace std;



unordered_map<int, int> cnt;
void solution() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cnt[num]++;
	}
	for (int i = 0; i < m; i++) {
		int find;
		cin >> find;
		cout << cnt[find] << " ";
	}
}
int main() {
	solution();
	return 0;
}

