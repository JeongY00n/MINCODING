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
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    queue<NODE>q;
    int used[101][101] = { 0 };

    //그저 1차 감염자가 두명일 뿐, 하나의 q로 채워가기
    q.push({ y1,x1 });
    q.push({ y2,x2 });
    used[y1][x1] = 1;
    used[y2][x2] = 1;
    

    int fy[] = { -1,1,0,0 };
    int fx[] = { 0,0,-1,1 };
    int ans = 0;

    while (!q.empty())
    {
        NODE now = q.front(); q.pop();

        //계속 업데이트 하다보면 화단에 꽃이 전부 피는데까지 걸리는 시간이 저장되고 끝남
        ans = used[now.row][now.col];

        for (int i = 0; i < 4; i++) 
        {
            int ny = now.row + fy[i];
            int nx = now.col + fx[i];

            if (ny < 0 || nx < 0)continue;
            if (ny >= row || nx >= col)continue;
            if (used[ny][nx] >= 1)continue;
            //특정 좌표 위치에 꽃이 피는데까지 걸린 시간
            used[ny][nx] = used[now.row][now.col] + 1;

            q.push({ ny,nx });
        }
    
    }
    cout << ans;
    
    return 0;
}