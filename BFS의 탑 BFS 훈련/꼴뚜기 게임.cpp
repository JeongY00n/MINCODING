#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE {
    int line;
    int num;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int n, k; cin >> n >> k;
    string str[3];

    cin >> str[0];
    cin >> str[2];

    queue<NODE>q;
    int used[100001] = { 0 };
    int check = 0;
    int cnt = 0;

    q.push({ 0, 0 });
    used[0] = 1;

    while (!q.empty()) {
        NODE now = q.front();
        q.pop();

        int line = now.line - 1;

        int nextList[3] = { now.num + 1, now.num - 1, now.num + k };
        int de = 1;


        for (int i = 0; i < 3; i++)
        {
            if (nextList[i] < 0) continue;

            //10000을 넘어가는걸로 완주가 가능하므로
            if (nextList[i] >= n)
            {
                check = 1;
                cout << 1;
                return 0;
            }
            if (i == 2)line *= -1;

            if (str[line + 1][nextList[i]] == '0')continue;

            if (used[nextList[i]] == 1)continue;
            cnt++;
            used[cnt] = 1;
            q.push({ line + 1, nextList[i] });
        }

    }

    if (!check)
        cout << 0;

    return 0;
}