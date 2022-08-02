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

    int arr[101][101] = { 0 };
    
    queue<NODE>q1;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int a; cin >> a;
            arr[i][j] = a;
        }
    }

    queue<NODE>q;
    int used[101][101] = { 0 };

    int fy[] = { -1,1,0,0 };
    int fx[] = { 0,0,-1,1 };
    int ans = 0;

    int check = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 2 && used[i][j] == 0)
            {
                q.push({ i,j });
                used[i][j] = 1;

                while (!q.empty())
                {

                    NODE now = q.front(); q.pop();
                    check = 0;

                    for (int i = 0; i < 4; i++) {
                        int cy = now.row + fy[i];
                        int cx = now.col + fx[i];

                        if (cy < 0 || cx < 0)continue;
                        if (cy >= row || cx >= col)continue;

                        if (arr[cy][cx] == 0)continue;
                        if (used[cy][cx] == 1) continue;
                        used[cy][cx] = 1;
                        q.push({ cy,cx });
                    }

                }
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}