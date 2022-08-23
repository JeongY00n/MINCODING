#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


//int parents[100001] = { 0 };
//int Find(int now) {
//	if (now == 0)
//		return 0;
//	if (parents[now] == 0)
//	{
//		parents[now] = now;
//		return now;
//	}
//	return parents[now] = Find(now-1);
//}
//
//int main()
//{
//
//	int g, p;
//	int car[100001];
//	cin >> g >> p;
//	for (int i = 1; i <= p; i++)
//	{
//		cin >> car[i];
//		parents[car[i]] = 0;
//	}
//	int cnt = 0;
//	for (int i = 1; i <= p; i++) {
//
//		if ((parents[car[i]] == 0))
//		{
//			parents[car[i]] = car[i];
//			cnt++;
//		}
//		else {
//			if (Find(car[i]))
//			{
//				cnt++;
//			}
//			else {
//				cout << cnt;
//				return 0;
//			}
//		}
//	}
//
//
//}


int parents[100001];
int Find(int now) {
	if (now == parents[now])
		return now;
	return parents[now] = Find(parents[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)return;

	parents[pb] = pa;
}

int main()
{

	int g, p;
	int car;
	cin >> g >> p;
	for (int i = 1; i <= g; i++)
	{
		parents[i] = i;
	}
	int cnt = 0;
	for (int i = 0; i < p; i++) {

		cin >> car;

		int find = Find(car);

		if (find == 0)
			break;
		// find가 0이 아닌 경우는 now == parents[now]

		cnt++;

		Union(find-1, find);
		
	}
	cout << cnt;

	return 0;

}