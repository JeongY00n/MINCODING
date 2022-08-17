#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main() {

	
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	while (1) {
		if (a == b)
			break;
		else if (a > b)
		{
			cnt = -1;
			break;
		}
		// a에 2를 곱해서 확인하는 대신 b를 2로 나눠서 확인
		// 1을 붙여주는 기준을 잡기가 어려움
		int division = b / 2;
		int mod = b % 2;
		
		if (mod == 0) {
			b /= 2;
		}
		else {
			b /= 10;
		}
		cnt++;

	}
	cout << cnt;
	return 0;

}