#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

struct Edge {
	int to, cost;
};

int n, robot1, robot2;
vector<Edge> v[100001];
int maxi = 0;
int ans = 0;
int check[100001] = { 0 };
void dfs(int now, int dist)
{
	vector<Edge> vnow = v[now];

	if (now == robot2)
	{
		ans = dist - maxi;
		return;
	}


	for (int i = 0; i < vnow.size(); i++)
	{
		if (check[vnow[i].to] == 1)continue;

		if (vnow[i].cost > maxi)
			maxi = vnow[i].cost;

		check[vnow[i].to] = 1;

		dfs(vnow[i].to, dist + vnow[i].cost);

		check[vnow[i].to] = 0;
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