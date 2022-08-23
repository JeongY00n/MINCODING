#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


struct Node {
	int go;
	int from, to;
};
int real_parents[200001];
int parents[200001];

int Find(int now) {
	if (parents[now] == now)
		return now;
	return parents[now] = Find(parents[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) return;

	parents[pb] = pa;
}

int main() {
	int n, q;
	int node_num;

	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> node_num;
		real_parents[i + 1] = node_num;
		parents[i] = i;
	}
	vector<Node> go;
	int op;
	for (int i = 1; i < n + q; i++)
	{
		cin >> op;
		if (op == 0) {
			int cut;
			cin >> cut;
			go.push_back({ 0,cut,0 });
		}
		else {
			int from, to;
			cin >> from >> to;
			go.push_back({ 1,from,to });
		}
	}

	stack<string> ans;

	for (int i = go.size() - 1; i >= 0; i--) {
		Node now = go[i];
		if (now.go == 1) {
			if (Find(now.from) == Find(now.to))
				ans.push("YES");
			else
				ans.push("NO");
		}
		else {
			Union(real_parents[now.from], now.from);
		}
	}

	while(!ans.empty()){
		cout << ans.top() << endl;
		ans.pop();
	}
}

