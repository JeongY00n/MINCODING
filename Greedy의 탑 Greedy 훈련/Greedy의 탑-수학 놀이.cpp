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
		// a�� 2�� ���ؼ� Ȯ���ϴ� ��� b�� 2�� ������ Ȯ��
		// 1�� �ٿ��ִ� ������ ��Ⱑ �����
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