#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int n, m, k, p; cin >> n >> m >> k >> p;
    vector<int> v[200001];
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
    }

    queue<int> q;
    int oil_cnt[200001] = { 0 };

    q.push(p);

    while (!q.empty()) 
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) 
        {
            int next = v[now][i];
            if (oil_cnt[next] >= 1) continue;
            oil_cnt[next] = oil_cnt[now] + 1;
            q.push(next);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (oil_cnt[i] == k)
        {
            cout << i << endl;
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << -1;
    }

    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int n, m, k, p; cin >> n >> m >> k >> p;
    vector<int> v[200001];
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
    }

    queue<int> q;
    int oil_cnt[200001] = { 0 };

    q.push(p);

    while (!q.empty()) 
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) 
        {
            int next = v[now][i];
            if (oil_cnt[next] >= 1) continue;
            oil_cnt[next] = oil_cnt[now] + 1;
            q.push(next);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (oil_cnt[i] == k)
        {
            cout << i << endl;
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << -1;
    }

    return 0;
}