#include <iostream>
#include<queue>
#include<vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //vector<int> v[100000]으로 두지 말고 100001으로 두어야함
    //왜 +1을 해주어야하지??
    vector<int> v[100001];
    int N; cin >> N;
    int M; cin >> M;


    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    int coco; cin >> coco;
    int used[100001] = { 0 };
    int cnt = 0;
    queue<int> q;

    q.push(coco);
    used[coco] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();


        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];

            if (used[next] == 1)continue;
            used[next] = 1;
            cnt++;
            q.push(next);
        }

    }
    cout << cnt;

    return 0;
}