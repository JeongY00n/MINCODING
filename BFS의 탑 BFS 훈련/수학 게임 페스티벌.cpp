#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int n; cin >> n;
    int password, pass;

    for (int i = 0; i < n; i++)
    {
        cin >> password >> pass;

        string out[10000];
        queue<int> q;
        int used[10000] = { 0 };

        q.push(password);
        used[password] = 1;
        while (!q.empty())
        {
            int now = q.front(); q.pop();

            if (now == pass)
            {
                for (int j = 0; j < out[now].size(); j++) {
                    cout << out[j];

                }cout << endl;
                break;
            }
            char nextList[4] = { 'D','S','L','R' };
            for (int j = 0; j < 4; j++) {
                int next;
                if (j == 0) {
                    next = (now * 2) % 10000;
                }
                else if (j == 1) {
                    if (now == 0)
                        next = 9999;
                    else
                        next = now - 1;
                }
                else if (j == 2) {
                    next = now % 1000 * 10 + now / 1000;
                }
                else if (j == 3) {
                    next = now / 10 + now % 10 * 1000;
                }

                if (used[next] == 1) continue;

                used[next] = 1;
                out[next].append(out[now]);
                out[next].push_back(nextList[j]);
                q.push(next);
            }

        }
    }

    return 0;
}