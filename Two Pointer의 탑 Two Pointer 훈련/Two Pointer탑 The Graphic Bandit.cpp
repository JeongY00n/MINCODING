#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


int main() {

	int N, M, P;
	int house[100001];
	cin >> N >> M >> P;
	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}

	int start = 0;
	int end = M - 1;
	int sum = 0;
	for (int i = start; i < end; i++)
		sum += house[i];


	int cnt = 0;
	while (start<N)
	{
		sum += house[end];
		if (sum < P)
		{
			cnt++;
			if (N == M)
				break;
		}
		sum -= house[start];

		start++;
		end++;
		if (end >= N)
			end -= N;

	}
	cout << cnt;

	
	return 0;
}