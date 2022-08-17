#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main() {

	int num, len;
	cin >> num >> len;
	int link[1001] = { 0 };
	for (int i = 0; i < num; i++) {
		cin >> link[i];
	}
	sort(link, link + num);

	int l = len, cnt = 0;
	for (int i = 0; i < num-1; i++) {
		l -= (link[i+1]-link[i]);
		if (l <= 0) {
			cnt++;
			l = len;
		}
	}
	cnt++;
	cout << cnt;

	return 0;

}