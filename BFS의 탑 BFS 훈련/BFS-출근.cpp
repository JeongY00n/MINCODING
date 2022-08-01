#include <iostream>
#include<queue>
#include<vector>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, m; cin >> n >> m;
    int arr[11][11] = { 0 };
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        arr[from][to] = 1;
        arr[to][from] = 1;
    }

    int T; cin >> T;

    queue<int> q;
    int used[11] = { 0 };

    q.push(1);
    used[1] = 1;
    used[T] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next = 1; next <= n; next++) {
            if (arr[now][next] == 0)continue;
            if (used[next] >= 1)continue;

            used[next] = used[now] + 1;
            q.push(next);
        }

    }
    if (used[n] == 0)
        cout << -1;
    else
        cout << used[n]-1;
    return 0;
}
