#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int to;
    int cost;
    int cnt;
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
int node, edge, years;
int start, dest;

void dijkstra()
{

    priority_queue<Edge, vector<Edge>, cmdstruct> pq;
    int dist[1001][1001];
    int used[1001] = { 0 };
    for (int i = 1; i <= node; i++)
        for (int j = 1; j <= node; j++)
            dist[i][j] = 2134567890;

    pq.push({ start, 0, 0 });
    dist[1][0] = 0;
    while (!pq.empty())
    {

        Edge now = pq.top(); pq.pop();

        if (used[now.to] == 1)continue;

        used[now.to] = 1;

        for (int i = 0; i < v[now.to].size(); i++)
        {
            Edge next = v[now.to][i];

            if (dist[next.to][now.cnt + 1] <= dist[now.to][now.cnt] + next.cost) continue;
            dist[next.to][now.cnt + 1] = dist[now.to][now.cnt] + next.cost;
            pq.push({ next.to, dist[next.to][now.cnt + 1], now.cnt + 1 });

        }
    }
    int ans = 999999999, in;
    for (int i = 1; i <= node; i++)
    {
        if (ans > dist[dest][i])
        {
            ans = dist[dest][i];
            in = i;
        }
    }cout << ans << endl;

    for (int year = 0; year < years; year++)
    {
        int C;
        cin >> C;
        int ans = 999999;

        for (int i = 1; i <= node; i++)
        {

            dist[dest][i] = dist[dest][i] + C * i;
            if (ans > dist[dest][i])
                ans = dist[dest][i];
        }
        cout << ans << endl;
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    cin >> node >> edge >> years;

    cin >> start >> dest;

    for (int i = 0; i < edge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
        v[to].push_back({ from, cost });
    }


    //매년 dijkstra를 돌리면 k(mlogn)의 시간 복잡도로 최악의 경우 90억 경우의 수가 발생
    // 최단 거리, 지나는 간선의 개수를 같이 구해주면 해결 가능
    //int total_impression = 0;


    dijkstra();

    return 0;
}
