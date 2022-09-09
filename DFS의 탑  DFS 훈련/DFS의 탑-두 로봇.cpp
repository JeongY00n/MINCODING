#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

struct Edge {
	int to, cost;
};

int n, robot1, robot2;
vector<pair<int, int>> v[100001];
int maxi = 0;
int ans = 0;
int check[100001] = { 0 };
void dfs(int now, int dist)
{
	vector<pair<int, int>> vnow = v[now];

	if (now == robot2)
	{
		ans = dist - maxi;
		return;
	}


	for (int i = 0; i < vnow.size(); i++)
	{
		if (check[vnow[i].first] == 0) {

			if (vnow[i].second > maxi)
				maxi = vnow[i].second;

			check[vnow[i].first] = 1;

			dfs(vnow[i].first, dist + vnow[i].second);

			check[vnow[i].first] = 0;
		}
	}

}



int main() {

	cin >> n >> robot1 >> robot2;

	for (int i = 0; i < n - 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}

	check[robot1] = 1;
	dfs(robot1, 0);
	cout << ans;

}