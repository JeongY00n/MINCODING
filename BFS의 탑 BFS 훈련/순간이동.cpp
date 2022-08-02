#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, m;
    cin >> n >> m;

    queue<int> q;
    int time[200001] = { 0 };
    int used[200001] = { 0 };

    q.push(n);
    used[n] = 1;

    while (!q.empty())
    {

        int now = q.front(); q.pop();

        if (now == m)
        {
            cout << time[now];
            break;
        }

        int nextList[3] = { now + 1, now - 1, now * 2 };
        for (int i = 0; i < 3; i++)
        {
            int next = nextList[i];
            if (next > 100000) continue;
            if (used[next] == 1)continue;

            used[next] = 1;
            time[next] = time[now] + 1;

            q.push(next);
        }
    }


    return 0;
}