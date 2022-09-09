#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;


// left�� right�� ã�Ƽ� �� �������� ������ ���ڰ� ����� �߻��ϴ��� Ȯ��


int main() {

	int de = 1;
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n, r;
		vector<int> food;
		cin >> n >> r;

		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			food.push_back(a);
		}
		int left = 0;
		int right = r * 2 + 1;
		int check[201] = { 0, };
		int flag = 0;
		while (left < n) {

			if (flag)
				break;

			memset(check, 0, sizeof(int)*200);

			for (int i = left; i < right; i++)
			{	
				if (i >= n)
				{
					check[food[i - n]]++;
					// ������ �߰��� ������ Ȯ���ؾ��Ѵ�!!
					if (check[food[i - n]] >= 3)
					{
						cout << "#" << tc << " " << "NO\n";
						flag = 1;
						break;
					}

				
				}
				else
				{
					
					check[food[i]]++;
					// ������ �߰��� ������ Ȯ���ؾ��Ѵ�!!
					if (check[food[i]] >= 3)
					{
						cout << "#" << tc << " " << "NO\n";
						flag = 1;
						break;
					}

				}
			}

			left++;
			right++;

		}

		if(!flag)
			cout << "#" << tc << " " << "YES\n";
	}
	
	
	return 0;
}