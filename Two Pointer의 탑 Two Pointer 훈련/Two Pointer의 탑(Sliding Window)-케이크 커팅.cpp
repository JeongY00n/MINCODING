#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;



int main() {

	int n;
	cin >> n;
	vector<char> cake;

	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		cake.push_back(a);
	}

	int left = 0;
	int right = n / 2 - 1;
	int k = 2, c1 = 0, c2 = 0;

	int check[2] = { 0 };
	int flag = 0;

	for (int i = left; i < right; i++)
	{
		int idx = 0;
		if (cake[i] == 's')
			idx = 1;
		check[idx]++;
	}

	while (1)
	{

		flag = 0;
		// Sliding Window 방식사용
		// sum[5~10] - cake[5] + cake[11] = sum[6~11]과 같은 방식
		if (cake[right] == 's')
			check[1]++;
		else
			check[0]++;

		if (check[0] > n / 4 || check[1] > n / 4)
		{
			flag = 1;
			if (cake[left] == 's')
				check[1]--;
			else
				check[0]--;
		}

		// 완료
		if (!flag) {
			if (left == 0 || right == n - 1)
				k = 1;
			c1 = left;
			c2 = right + 1;
			break;
		}

		left++;
		right++;

	}

	cout << k << "\n";
	if (k == 1 && c1 == 0)
		cout << c2;
	else if (k == 1 && c2 == n)
		cout << c1;
	else if (k == 2)
		cout << c1 << " " << c2;


	return 0;
}