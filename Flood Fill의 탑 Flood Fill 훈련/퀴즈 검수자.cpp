#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE {
    int row;
    int col;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int row, col; cin >> row >> col;
    int y1, x1;
    cin >> y1 >> x1;
    int y2, x2;
    cin >> y2 >> x2;
    int n;
    cin >> n;
    int used[101][101] = { 0 };

    for (int i = 0; i < n; i++) {
        int y, x;
        cin >> y >> x;
        used[y][x] = 1;
    }

    queue<NODE>q1;
    q1.push({ y1,x1 });
    used[y1][x1] = 1;
    used[y2][x2] = 0;

    int fy[] = { -3,-2,2,3,3,2,-2,-3 };
    int fx[] = { -2,-3,-3,-2,2,3,3,2 };
    int ans = 0;
    while (!q1.empty())
    {
        NODE now = q1.front(); q1.pop();

        ans = used[now.row][now.col];

        for (int i = 0; i < 8; i++) {
            int cy = now.row + fy[i];
            int cx = now.col + fx[i];

            if (cy < 0 || cx < 0)continue;
            if (cy >= row || cx >= col)continue;
            if (used[cy][cx] >= 1)continue;


            used[cy][cx] = used[now.row][now.col]+ 1;

            q1.push({ cy,cx });
        }
    }

    cout << used[y2][x2]-1;

    return 0;
}