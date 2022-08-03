#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE {
    int row;
    int col;
};

int n;
queue<NODE> q;
string map[6];
int used1[6][6] = { 0 };
int used2[6][6] = { 0 };
void findsis1( int y, int x)
{

    q.push({ y,x });
    used1[y][x] = 1;

    while (!q.empty()) {
        NODE now = q.front();
        q.pop();

        int fy[] = { -1,1,0,0 };
        int fx[] = { 0,0,-1,1 };
        for (int i = 0; i < 4; i++) {
            int ny = fy[i] + now.row;
            int nx = fx[i] + now.col;

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (used1[ny][nx] >= 1)continue;
            if (map[ny][nx] == '#')continue;

            used1[ny][nx] = used1[now.row][now.col]+1;

            q.push({ ny,nx });
        }
    }

}
void findsis2(int y, int x)
{

    q.push({ y,x });
    used2[y][x] = 1;

    while (!q.empty()) {
        NODE now = q.front();
        q.pop();

        int fy[] = { -1,1,0,0 };
        int fx[] = { 0,0,-1,1 };
        for (int i = 0; i < 4; i++) {
            int ny = fy[i] + now.row;
            int nx = fx[i] + now.col;

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (used2[ny][nx] >= 1)continue;
            if (map[ny][nx] == '#')continue;

            used2[ny][nx] = used2[now.row][now.col] + 1;
            q.push({ ny,nx });
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    /*
        ##푸는 방법##

        1. 각 시간별로 두 캐릭터를 동시에 옮겨주는 방법
        struct NODE{
            int Arow, Acol, Brow, Bcol;
        }
        =====> used[Arow][Acol][Brow][Bcol]로 구성

        2. 
        3. 최대한 적은 node를 밟아서 가는 '경로'찾기
        BFS()사용
        한명에서 다른 한명까지 이동
        uesd/2가 답 BUT) 홀수인경우 짝수인 경우에서 발생하는 오차 신경쓰기
    */
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> map[i];

    }
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    findsis1(y1, x1);
    findsis2(y2, x2);


    int min = 999999;
    // 모든 점에 대해서 엘사 안나가 만나기까지 필요한 시간은
    // 두 used1, used2에 대해서 큰값으로 설정해주면 된다
    // 그리고 만들어진 used에서 가장 작은 값으로 출력하면 된다
    int used[6][6] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (used1[i][j] > used2[i][j])
                used[i][j] = used1[i][j];
            else
                used[i][j] = used2[i][j];

            if (min > used[i][j] and used[i][j]!=0)
                min = used[i][j];
        }
    }
    cout << min-1;

    return 0;
}