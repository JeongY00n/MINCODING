#include <iostream>
#include<queue>
#include<vector>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int arr[6][6] = {
        0,0,0,0,1,0,
        1,0,1,0,0,1,
        1,0,0,1,0,0,
        1,1,0,0,0,0,
        0,1,0,1,0,1,
        0,0,1,1,0,0
    };
    int start; cin >> start;

    queue<int> q;
    int used[6] = { 0 };

    q.push(start);
    used[start] = 1;

    while (!q.empty()) {

        int now = q.front();
        q.pop();

        cout << now << endl;

        for (int next = 0; next < 6; next++) {
            if (arr[now][next] == 0)continue;
            if (used[next] == 1)continue;
            used[next] = 1;
            q.push(next);
        }
    }



    return 0;
}
