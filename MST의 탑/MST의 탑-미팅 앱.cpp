#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

struct Edge {
	int from, to, dist;
};
bool cmp(Edge a, Edge b) {
	if (a.dist < b.dist)return true;
	if (a.dist > b.dist)return false;

	return false;
}

vector<Edge> edge;
int parents[1001];

int Find(int now) {
	if (now == parents[now])
		return now;
	return parents[now] = Find(parents[now]);
}
void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	parents[pb] = pa;
}

int main() {
	int n, m;
	char gen[1001];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> gen[i];
		parents[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		edge.push_back({ from, to, dist });
	}

	sort(edge.begin(), edge.end(), cmp);
	int sum = 0;
	int cnt = 0;

	for (int i = 0; i < edge.size(); i++) {

		Edge now = edge[i];
		int from = now.from;
		int to = now.to;
		if (gen[from] == gen[to])continue;
		if (Find(from) == Find(to))continue;

		Union(from, to);
		sum += now.dist;
		cnt++;
	}
	if (cnt == n-1)
		cout << sum;
	else
		cout << -1;
	


	return 0;
}