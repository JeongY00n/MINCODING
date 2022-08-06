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
int start, last;
void dijkstra(int impression)
{

    priority_queue<Edge, vector<Edge>, cmdstruct> pq;
    int dist[1001];
    int used[1001] = { 0 };

    for (int i = 0; i < 1001; i++)
        dist[i] = 2134567890;

    pq.push({ start, 0 });
    dist[start] = 0;


    while (!pq.empty())
    {

        Edge now = pq.top(); pq.pop();

        if (used[now.to] == 1)continue;

        used[now.to] = 1;

        for (int i = 0; i < v[now.to].size(); i++) {
            Edge next = v[now.to][i];

            //가격 인상
            next.cost += impression;

            if (next.cost + dist[now.to] >= dist[next.to]) continue;

            //dist갱신
            dist[next.to] = next.cost + dist[now.to];
            pq.push({ next.to, dist[next.to] });

        }

        //도달 지점에 도착했으면 dist값 출력
        if (now.to == last)
        {
            cout << dist[now.to] << endl;
        }

    }



}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    
    int node, edge, years;
    cin >> node >> edge >> years;

    cin >> start >> last;

    for (int i = 0; i < edge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
        v[to].push_back({ from, cost });
    }

    dijkstra(0);
    int total_impression = 0;
    for (int i = 0; i < years; i++) {
        int impression;
        cin >> impression;
        total_impression += impression;
        dijkstra(total_impression);
    }

    return 0;
}
