#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



int main() {

	int n, m;
	int arr[100001] = { 0 };
	int sum[100001] = { 0 };
	cin >> n >> m;
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		result = result + arr[i];
		sum[i] = result;
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a] + arr[a] << endl;
	}

	return 0;

}