#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE {
    int row;
    int col;
};

int n, m, cnt;
char map[21][21];


void find_CD(int y, int x, char c) {
    queue<NODE> q;

    int used[21][21] = { 0 };

    q.push({ y,x });
    used[y][x] = 1;

    while (!q.empty()) {
        NODE now = q.front();
        q.pop();


        int fy[] = { -1,1,0,0 };
        int fx[] = { 0,0,-1,1 };

        for (int i = 0; i < 4; i++) {
            int ny = now.row + fy[i];
            int nx = now.col + fx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (map[ny][nx] == c)
            {
                cnt = used[now.row][now.col];
                return;
            }
            if (used[ny][nx] != 0)continue;
            if (map[ny][nx] != '.')continue;

            used[ny][nx] = used[now.row][now.col] + 1;
            // cout << ny << "," << nx << " " << used[ny][nx] << endl;

            q.push({ ny,nx });
        }

    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;
    int sy = 0, sx = 0, cy = 0, cx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'S')
            {
                sy = i; sx = j;
            }

            if (map[i][j] == 'C')
            {
                cy = i; cx = j;
            }
        }
    }

    int result = 0;

    find_CD(sy, sx, 'C');
    result += cnt;

    find_CD(cy, cx, 'D');
    result += cnt;

    cout << result;

    return 0;
}