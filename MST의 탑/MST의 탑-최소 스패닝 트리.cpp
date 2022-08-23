#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


struct Edge {
	int from, to, cost;
};
bool cmp(Edge a, Edge b) {
	if (a.cost < b.cost)return true;
	if (a.cost > b.cost)return false;

	return false;
}
vector<Edge> edge;
int parents[10001];
int Find(int now) {
	if (parents[now] == now)
		return now;
	return parents[now] = Find(parents[now]);
}
void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)return;

	parents[pb] = pa;
	
}
int main(){

	int v, e;

	for (int i = 1; i <= v; i++)
		parents[i] = i;

	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back({ from,to,cost });
	}
	sort(edge.begin(), edge.end(), cmp);

	int sum = 0;
	for (int i = 0; i < v; i++) {
		
		Edge now = edge[i];
		int from = now.from;
		int to = now.to;

		if (Find(from) == Find(to))continue;

		Union(from, to);

		sum += now.cost;
	}

	cout << sum;



}