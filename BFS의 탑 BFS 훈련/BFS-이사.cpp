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

    int office, good;
    cin >> office >> good;

    queue<int> q;
    int used[11] = { 0 };

    q.push(office);
    used[office] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next = 1; next <= n; next++) {

            if (arr[now][next] == 0)continue;
            if (used[next] > 0)continue;
            used[next] = used[now] + 1;
            
            q.push(next);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        //����� ������ used�� ����߱� ������ ��������good�� +1�� ������Ѵ�
        if (used[i] > good + 1 || used[i] <= 0)continue;
        cnt++;
    }
    cout << cnt;


    return 0;
}
