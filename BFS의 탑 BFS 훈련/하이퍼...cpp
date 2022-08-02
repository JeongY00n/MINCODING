#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int n, k, m;
    cin >> n >> k >> m;
    vector<int> v[120001];
    int node = n + 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            v[node].push_back(a);
            v[a].push_back(node);
        }
        node++;
    }

    queue<int> q;
    int used[120001] = { 0 };

    used[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (used[next] >= 1) continue;
            if (next <= n)
                used[next] = used[now] + 1;
            else
                used[next] = used[now];
            q.push(next);
        }
    }
    if (used[n] == 0)
        cout << -1;
    else
        cout << used[n];


    return 0;
}