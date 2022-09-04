#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

struct Edge {
    int to, cost;
};


int N, node1, node2;
vector<Edge> v[100001];
int visited[100001] = { 0 };
int maxi = 0;

int dfs(int now) 
{
    int ans = 0;
    visited[now] = 1;

    for (int i = 0; i < v[now].size(); i++) 
    {
        int to = v[now][i].to;
        int cost = v[now][i].cost;

        if (visited[to] == 1) continue;

        ans = dfs(to);
        if (ans > 0 || to == node2)
        {
            maxi = max(maxi, cost);
            ans += cost;
            break;
        }
    }
    return ans;
}

int main() {

    
    cin >> N >> node1 >> node2;

    for (int i = 0; i < N - 1; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
        v[to].push_back({ from, cost });
    }

    int dist = dfs(node1);
    int ans = dist - maxi;

    cout << ans;

    return 0;
}