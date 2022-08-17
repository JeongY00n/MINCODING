#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



// 가장 빨리 끝나는 순서대로 정렬

struct Meeting {
	int st;
	int en;
};
bool order(Meeting a, Meeting b) {
	if (a.en > b.en)return false;
	if (a.en < b.en)return true;
	if (a.st > b.st)return false;
	if (a.st < b.st)return true;

	return false;
}
int main() {

	int n;
	cin >> n;
	Meeting meeting[100001];

	for (int i = 0; i < n; i++) {
		cin >> meeting[i].st >> meeting[i].en;
	}
	sort(meeting, meeting + n, order);

	int last = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (last <= meeting[i].st)
		{
			last = meeting[i].en;
			cnt++;
		}

	}

	cout << cnt;
	return 0;

}