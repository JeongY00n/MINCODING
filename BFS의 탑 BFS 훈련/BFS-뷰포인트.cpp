#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int to;
    int cost;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int N, M, K;
    cin >> N >> M >> K;
    vector<Edge> v[100001];

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
        v[to].push_back({ from, cost });
    }

    queue<int> q;

    //양방향의 경우 cycle발생 가능
    int used[100001] = { 0 };

    //해당 노드까지 필요한 체력
    //int 는 21억보다 조금 더 큼
    long long hp[100001] = { 0 };



    q.push(1);
    used[1] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++)
        {
            Edge next = v[now][i];

            if (used[next.to] == 1)continue;

            used[next.to] = 1;
            hp[next.to] = hp[now] + next.cost;

            q.push(next.to);
        }

    }

    int cnt = 0;
    for (int i = 2; i <= N; i++)
    {
        if (hp[i] <= K)
            cnt++;
    }
    cout << cnt;


    return 0;
}