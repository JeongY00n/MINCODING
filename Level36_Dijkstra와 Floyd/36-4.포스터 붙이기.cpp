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


int C, P, K, A, B;
vector<Edge> v[100001];
priority_queue<Edge, vector<Edge>, cmdstruct> pq;

void dijkstra(int start, int* dist)
{
    pq.push({ start, 0 });

    for (int i = 1; i <= P; i++)
        dist[i] = 2134567890;

    dist[start] = 0;

    int used[100001] = { 0 };
    
    while (!pq.empty()) {

        Edge now = pq.top(); pq.pop();

        if (used[now.to] == 1)continue;
        used[now.to] = 1;


        for (int i = 0; i < v[now.to].size(); i++) {
            Edge next = v[now.to][i];

            if (dist[next.to] <= dist[now.to] + next.cost)continue;
            dist[next.to] = dist[now.to] + next.cost;

            pq.push({ next.to, next.cost });
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> C >> P >> K >> A >> B;

    for (int i = 0; i < C; i++) {
        int p1, p2, d;
        cin >> p1 >> p2 >> d;
        v[p1].push_back({ p2,d });
        v[p2].push_back({ p1,d });
    }

    int dist1[100001];
    dijkstra(K, dist1);
    int dist2[100001];
    dijkstra(A, dist2);


    return 0;
}


