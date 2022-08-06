#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int to;
    int cost;
};

struct cmdstruct {
    bool operator()(Edge A, Edge B) {
        if (A.cost < B.cost)return false;
        if (A.cost > B.cost)return true;

        if (A.to < B.to)return false;
        if (A.to > B.to)return true;

        return false;
    }

};


vector<Edge> v[1001];
int node, edge, P;

void dijkstra(int start, int* dist)
{
    
    priority_queue<Edge, vector<Edge>, cmdstruct> pq;
    //int used[1001] = { 0 };

    for (int i = 1; i <= node; i++)
        dist[i] = 2134567890;

    pq.push({ start,0 });
    dist[start] = 0;

    while (!pq.empty()) {
        Edge now = pq.top(); pq.pop();

        //if (used[now.to] == 1)continue;
        //단방향 간선이라 used필요 없음
        //used[now.to] = 1;

        for (int i = 0; i < v[now.to].size(); i++) {
            Edge next = v[now.to][i];
            
            if (dist[next.to] <= dist[now.to] + next.cost)continue;

            dist[next.to] = dist[now.to] + next.cost;

            pq.push({ next.to, dist[next.to] });
        }

    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    priority_queue<int> result;

    cin >> node >> edge >> P;

    for (int i = 0; i < edge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
    }

    //스터디 장소에서 집으로 돌아가는 길
    int dist_P[1001] = { 0 };
    dijkstra(P, dist_P);
    

    //집에서 스터디 장소로 가는 길
    for (int i = 1; i <= node ; i++) {
        if (i == P)continue;
        int dist[1001] = { 0 };
        dijkstra(i, dist);
        result.push(dist[P] + dist_P[i]);
    }

    cout << result.top();

    return 0;
}
