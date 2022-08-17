#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main() {

	int num;
	int coin[4] = { 500,100,50,10 };
	cin >> num;
	int cnt = 0, i = 0;
	while (num) {
		if (num / coin[i] != 0)
		{
			cnt += num / coin[i];
			num %= coin[i];
		}
		i++;
	}
	cout << cnt;

	return 0;

}