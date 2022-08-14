#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    int row;
    int col;
    int cost;
};

struct cmpstruct {
    bool operator()(Node a, Node b) {
        if (a.cost < b.cost)return false;
        if (a.cost > b.cost)return true;

        if (a.row < b.row)return false;
        if (a.row > b.row)return true;

        if (a.col < b.col)return false;
        if (a.col > b.col)return true;

        return false;

    }
};

int n, m;
int map[101][101] = { 0 };
priority_queue<Node, vector<Node>, cmpstruct> pq;
void dijkstra() {
    int dist[101][101];
    int used[101][101] = { 0 };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = 2134567890;
        }
    }

    pq.push({ 1, 1, map[1][1] });
    dist[1][1] = map[1][1];

    int fy[] = { -1,1,0,0 };
    int fx[] = { 0,0,-1,1 };

    while (!pq.empty()) {

        Node now = pq.top();
        pq.pop();

        if (now.row == n && now.col == m) {
            cout << dist[now.row][now.col];
            return;
        }

        if (used[now.row][now.col] == 1) continue;
        used[now.row][now.col] = 1;

        for (int i = 0; i < 4; i++) {
            int ny = fy[i] + now.row;
            int nx = fx[i] + now.col;

            if (ny < 1 || nx < 1 || ny > n || nx > m)continue;
            if (dist[ny][nx] < dist[now.row][now.col] + map[ny][nx]) continue;
            dist[ny][nx] = dist[now.row][now.col] + map[ny][nx];
            pq.push({ ny, nx, dist[ny][nx] });
        }

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    dijkstra();

    return 0;
}