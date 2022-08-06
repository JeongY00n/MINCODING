#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE {
    int to;
    int cost;
};

struct cmdstruct {
    bool operator()(NODE  A, NODE B) {
        if (A.cost < B.cost) return false;
        if (A.cost > B.cost) return true;

        if (A.to < B.to) return false;
        if (A.to > B.to) return true;

        return false;
    }
};

vector<NODE> v[20001];
priority_queue<NODE, vector<NODE>, cmdstruct> pq;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, t;
    cin >> n >> t;
    
    for (int i = 0; i < t; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
    }
    
    int dist[20001];
    int used[20001] = { 0 };

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 2134567890;
    }

    dist[0] = 0;
    pq.push({ 0,0 });

    int check = 0;
    while (!pq.empty()) {

        int now = pq.top().to;
        int nowDist = pq.top().cost;
        pq.pop();

        if (used[now] == 1) continue;
        
        used[now] = 1;

        for (int i = 0; i < v[now].size(); i++) {
            NODE node = v[now][i];
            int next = node.to;
            int edgeDist = node.cost;

            if (dist[now] + edgeDist > dist[next]) continue;

            dist[next] = dist[now] + edgeDist;
            pq.push({ next, dist[next] });

        }
        if (now == n - 1) {
            cout << dist[now];
            check = 1;
        }
    }

    if (!check)
        cout << "impossible";
    return 0;
}
