#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE {
    int row;
    int col;
};

string arr[8];
int used[8][9] = { 0 };
queue<NODE> q;
queue<NODE> border;
void bfs(int y, int x) {

    q.push({ y,x });

    int fy[] = { -1,1,0,0 };
    int fx[] = { 0,0,-1,1 };

    while (!q.empty())
    {
        NODE now = q.front();
        q.pop();


        for (int i = 0; i <4; i++ )
        {
            int ny = now.row + fy[i];
            int nx = now.col + fx[i];

            if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9)continue;
            if (used[ny][nx] != 0)continue;
            used[ny][nx] = 1;
            if (arr[ny][nx] == '_') 
            { 
                //사람 테두리를 먼저 큐에 다 넣어주면서 시작
                //그래야 테두리 따라서 이동 경로가 순차적으로 커짐
                border.push({ ny,nx });
                continue; 
            }

            q.push({ ny,nx });
        }
    }
}

void bfs2() 
{

    int fy[] = { -1,1,0,0 };
    int fx[] = { 0,0,-1,1 };

    while (!border.empty())
    {
        NODE now = border.front();
        border.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = now.row + fy[i];
            int nx = now.col + fx[i];

            if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9)continue;
            //다른 사람
            if (used[ny][nx] > 1)continue;
            if (arr[ny][nx] == '#')
            {
                cout<< used[now.row][now.col];
                return;
            }

            used[ny][nx] = used[now.row][now.col] + 1;

            border.push({ ny,nx });

        }

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    for (int i = 0; i < 8; i++)
        cin >> arr[i];

    bfs(0, 8); 
   
    bfs2();
    return 0;
}