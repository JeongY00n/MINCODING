#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

struct Node {
	double y, x;
};

struct Edge {
	int from, to;
	double dist;
};
bool cmp(Edge a, Edge b) {
	if (a.dist < b.dist)return true;
	if (a.dist > b.dist)return false;

	return false;
}
vector<Node> star;
vector<Edge> edge;
int parents[101];


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
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		parents[i] = i;

	for (int i = 0; i < n; i++)
	{
		double y, x;
		cin >> y >> x;
		star.push_back({ y,x });
	}

	//round(pi * 100) / 100
	for (int i = 0; i < star.size(); i++) {
		Node now = star[i];
		for (int j = i + 1; j < star.size(); j++) {
			Node next = star[j];
			double dist = (now.y - next.y) * (now.y - next.y) + (now.x - next.x) * (now.x - next.x);

			edge.push_back({ i, j, dist });
		}
	}

	sort(edge.begin(), edge.end(), cmp);
	double sum = 0;

	for (int i = 0; i < edge.size(); i++) {
		Edge now = edge[i];
		int from = now.from;
		int to = now.to;

		if (Find(from) == Find(to))continue;

		Union(from, to);
		double re_dist = sqrt(now.dist);
		sum += re_dist;

	}

	cout << round(sum * 100) / 100;


}