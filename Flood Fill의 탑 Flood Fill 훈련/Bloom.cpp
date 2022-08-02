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

    //���� 1�� �����ڰ� �θ��� ��, �ϳ��� q�� ä������
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

        //��� ������Ʈ �ϴٺ��� ȭ�ܿ� ���� ���� �Ǵµ����� �ɸ��� �ð��� ����ǰ� ����
        ans = used[now.row][now.col];

        for (int i = 0; i < 4; i++) 
        {
            int ny = now.row + fy[i];
            int nx = now.col + fx[i];

            if (ny < 0 || nx < 0)continue;
            if (ny >= row || nx >= col)continue;
            if (used[ny][nx] >= 1)continue;
            //Ư�� ��ǥ ��ġ�� ���� �Ǵµ����� �ɸ� �ð�
            used[ny][nx] = used[now.row][now.col] + 1;

            q.push({ ny,nx });
        }
    
    }
    cout << ans;
    
    return 0;
}