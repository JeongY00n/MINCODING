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

    int y, x;
    cin >> y >> x;
    int arr[5][5] = { 0 };
    int fy[] = {-1,0,0,1};
    int fx[] = {0,-1,1,0};

    queue<NODE> q;
    int used[5][5] = { 0 };

    q.push({ y,x });
    used[y][x] = 1;
   
    while (!q.empty()) {
        NODE now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nexty = now.row + fy[i];
            int nextx = now.col + fx[i];

            if (nexty < 0 || nextx < 0)continue;
            if (nexty >= 5 || nextx >= 5)continue;
            if (used[nexty][nextx] >= 1)continue;

            used[nexty][nextx] = used[now.row][now.col] + 1;
            q.push({ nexty, nextx });
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << used[i][j] << " ";
        }cout << endl;
    }
    
    return 0;
}