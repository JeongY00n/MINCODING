#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



// 한 과목(co)에 대해 정렬을 하고 그 과목(co) 1등의 다른 과목(in)을 변수에 저장
// 변수(in)에 저장한 값을 다른 학생들과 비교하면서 변수 값(in) 보다 큰 경우는 제외
// 변수(in)보다 작은 경우 그 값(in)으로 갱신해준다

struct STUDENT {
	int co;
	int in;
};
bool order(STUDENT a, STUDENT b) {

	if (a.co > b.co)return false;
	if (a.co < b.co)return true;

	return false;
}
int main() {

	int n;
	vector<STUDENT> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int co, in;
		cin >> co >> in;
		v.push_back({ co,in });
	}
	sort(v.begin(), v.end(), order);
	int cnt = n;
	int front = v.front().in;
	for (int i = 1; i < n; i++) {
		if (front > v[i].in)
			front = v[i].in;
		else
		{
			cnt--;
		}
	}

	cout << cnt;
	return 0;

}