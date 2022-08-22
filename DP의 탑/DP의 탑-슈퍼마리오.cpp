#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;




int map[151] = { 0 };
int dp[151] = { 0 };
int Jump(int n) {

	if (n == 0)return 0;
	if (n < 0)return -9999999;
	if (dp[n] != 0)return dp[n];
	
	int a = Jump(n - 2);
	int b = Jump(n - 7);

	int maxValue = max(a, b);

	dp[n] = maxValue + map[n];
	return dp[n];

}

int main() {
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> map[i];

	int maxValue = -2134567890;
	for (int i = 1; i <= 5; i++) 
		 maxValue= max(Jump(n + i), maxValue);
		
	cout<< maxValue;

	return 0;

}