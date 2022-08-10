#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//입력값이 edge의 cost값이 아니라 node 한개에 대한 cost값이므로 
struct NODE {
    int row;
    int col;
    int cost;
};

struct cmpstruct {
    bool operator()(NODE a, NODE b) {
        if (a.cost < b.cost)return false;
        if (a.cost > b.cost)return true;

        return false;
    }
};

int y, x, n;
int MAP[1001][1001];
priority_queue<NODE, vector<NODE>, cmpstruct> pq;

void dijkstra(int max_y, int max_x) {
    int used[1001][1001] = { 0 };
    int dist[1001][1001] = { 0 };
    
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            dist[i][j] = 2134567890;

    pq.push({ y, x, 0 });
    dist[y][x] = MAP[y][x];

    while (!pq.empty()) {

        NODE now = pq.top();
        pq.pop();

        //재방문 하지 않기 위해
        if (now.row==max_y && now.col==max_x)
        {
            cout << dist[now.row][now.col];
            return;
        }

        if (used[now.row][now.col] == 1)continue;
        used[now.row][now.col] = 1;

        int fy[] = { 0,0,-1,1 };
        int fx[] = { -1,1,0,0 };
        for (int i = 0; i < 4; i++) {
            int ny = fy[i] + now.row;
            int nx = fx[i] + now.col;

            if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
            if (MAP[ny][nx] == -1)continue;
            if (dist[ny][nx] < dist[now.row][now.col] + MAP[ny][nx])continue;
            dist[ny][nx] = dist[now.row][now.col] + MAP[ny][nx];

            pq.push({ ny, nx, dist[ny][nx] });
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> y >> x;
    cin >> n;
    int max = 0, max_y, max_x;
    for (int from = 0; from < n; from++) {
        for (int to = 0; to < n; to++) {
            int a;
            cin >> a;
            MAP[from][to] = a;
            // 가장 높은 cost값의 위치를 찾기
            if (max < a)
            {
                max = a;
                max_x = to; max_y = from;
            }
        }
    }
    dijkstra(max_y, max_x);

    return 0;
}