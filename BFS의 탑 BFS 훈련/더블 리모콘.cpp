#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int s, d; cin >> s >> d;

    queue<int> q;
    int used[100001] = { 0 };

    q.push(s);
    used[s] = 1;

    while (!q.empty()) {

        int now = q.front(); q.pop();

        if (now == d)
        {
            cout << used[now]-1;
            break;
        }

        int nextList[] = { now / 2, now * 2, now + 1, now - 1 };
        for (int i = 0; i < 4; i++) {
            int next = nextList[i];
            if (next < 0 || next > 100000) continue;
            if (used[next] >= 1) continue;

            used[next] = used[now] + 1;

            q.push(next);
        }
    }


    return 0;
}