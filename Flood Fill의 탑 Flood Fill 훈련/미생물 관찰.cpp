#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE {
    int row;
    int col;
};

int n, m;
char map[201][201];
int used[201][201] = {0};
queue<NODE> q;
int MAX = 0;

void find_micro(int y, int x, char c) {

    q.push({ y,x });
    used[y][x] = 1;
    //미생물 사이즈
    int size = 1;
    while (!q.empty()) {
        NODE now = q.front();
        q.pop();


        int fy[] = { -1,1,0,0 };
        int fx[] = { 0,0,-1,1 };

        for (int i = 0; i < 4; i++) {
            int ny = now.row + fy[i];
            int nx = now.col + fx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (used[ny][nx] != 0)continue;
            if (map[ny][nx] != c)continue;

            used[ny][nx] = 1;
            size++;
            q.push({ ny,nx });
        }
        
        if (MAX < size)
            MAX = size;
    }



}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cin >> map[i][j];   
    }
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j] == 0 and map[i][j]=='A') {
                find_micro(i, j, 'A');
                cnt_a++;
            }
            if (used[i][j] == 0 and map[i][j] == 'B') {
                find_micro(i, j, 'B');
                cnt_b++;
            }
        }
    }

    cout << cnt_a << " " << cnt_b << endl;
    cout << MAX;

    return 0;
}