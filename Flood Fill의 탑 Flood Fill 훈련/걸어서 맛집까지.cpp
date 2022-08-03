#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE {
    int row;
    int col;
};

int n, m;
int map[201][201] = { 0 };
int used[201][201] = { 0 };
queue<NODE> q;

queue<NODE> findborder(int y, int x) {

    queue<NODE> border;
    q.push({ y,x });
    used[y][x] = 1;

    while (!q.empty()) {

        NODE now = q.front();
        q.pop();

        int fy[] = { -1,1,0,0 };
        int fx[] = { 0,0,-1,1 };
        for (int i = 0; i < 4; i++) {
            int ny = fy[i] + now.row;
            int nx = fx[i] + now.col;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if (used[ny][nx] == 1)continue;

            used[ny][nx] = 1;

            if (map[ny][nx] == 0) 
            { 
                border.push({ ny,nx });
                continue; 
            }

            q.push({ ny,nx });
        }
    }
    return border;
}

void finddistance(queue<NODE> b) {

    while (!b.empty()) {
        NODE now = b.front();
        b.pop();
        
        int fy[] = { -1,1,0,0 };
        int fx[] = { 0,0,-1,1 };
        for (int i = 0; i < 4; i++) {
            int ny = fy[i] + now.row;
            int nx = fx[i] + now.col;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if (used[ny][nx] >= 1)continue;
            if (map[ny][nx] != 0) {
                cout << used[now.row][now.col];
                return;
            }

            used[ny][nx] = used[now.row][now.col] + 1;
            b.push({ ny,nx });
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;
    int starty, startx;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0)
            {
                starty = i;
                startx = j;
            }
        }
    }

    queue<NODE> b = findborder(starty, startx);

    finddistance(b);

    return 0;
}