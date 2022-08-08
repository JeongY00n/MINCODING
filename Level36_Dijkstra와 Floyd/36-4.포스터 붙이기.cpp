#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int to;
    int cost;
};

struct cmpstruct {
    bool operator()(Edge a, Edge b) {
        if (a.cost < b.cost)return false;
        if (a.cost > b.cost)return true;

        return false;
    }
};
int edge, node, K, A, B;
priority_queue<Edge, vector<Edge>, cmpstruct> pq;
vector<Edge> v[100001];
int result = 0;
int dijkstra(int k) {
    int used[100001] = { 0 };
    int dist[100001] = { 0 };

    for (int i = 1; i <= node; i++)
        dist[i] = 2134567890;

    pq.push({ k,0 });
    dist[k] = 0;
    
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        if (used[now.to] == 1)continue;

        used[now.to] = 1;

        for (int i = 0; i < v[now.to].size(); i++) {
            Edge next = v[now.to][i];

            if (dist[next.to] < dist[now.to] + next.cost) continue;
            dist[next.to] = dist[now.to] + next.cost;
            pq.push({ next.to, dist[next.to] });
        }
    }
    if (k == K) {
        if (dist[A] < dist[B])
        {
            result += dist[A];
            return A;
        }
        else
        {
            result += dist[B];
            return B;
        }
    }
    else if (k == A)
    {
        result += dist[B];
        return result;
    }
    else if (k == B)
    {
        result += dist[A];
        return result;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> edge >> node >> K >> A >> B;

    for (int i = 0; i < edge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to,cost });
        v[to].push_back({ from,cost });
    }

    int next = dijkstra(K);
    result = dijkstra(next);

    cout << result;

    return 0;
}