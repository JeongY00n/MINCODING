#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct NODE {
    int row;
    int col;
    int num;
};

struct order {
    bool operator()(NODE a, NODE b) {

        if (a.num < b.num)return false;
        if (a.num > b.num)return true;

        return false;
    }
};

priority_queue<NODE, vector<NODE>, order> q;
int n;
int map[1001][1001] = { 0 };
int used[1001] = { 0 };
int last = 0;

void boom() {

    int fy[] = { -1,1,0,0 };
    int fx[] = { 0,0,-1,1 };

    while (!q.empty()) {

        NODE now = q.top();
        q.pop();
        // 폭탄이 터진 경우 다시 터질 수 없으므로
        // 다른 폭탄에 의해 터진 경우 제외시킨다.(조건 필수!)
        if (used[now.num] == 1) continue;
        // 계속 갱신하다보면 마지막까지 남아있게 되는 폭탄의 번호가 저장될 것이다
        last = now.num;
        used[now.num] = 1;


        for (int i = 0; i < 4; i++) {
            int ny = fy[i] + now.row;
            int nx = fx[i] + now.col;

            if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
            if (used[map[ny][nx]] == 1)continue;

            used[map[ny][nx]] = 1;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            q.push({ i, j, map[i][j] });
        }
    }

    boom();
    cout << last << "초";

    return 0;
}