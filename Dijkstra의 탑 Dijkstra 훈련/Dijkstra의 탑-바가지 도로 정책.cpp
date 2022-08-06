#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int to;
    int cost;
    int add_cost;
    int time;
    int cnt;
};

struct cmdstruct {
    bool operator()(Edge A, Edge B) {
        if (A.cost < B.cost)return false;
        if (A.cost > B.cost)return true;

        if (A.time < B.time)return false;
        if (A.time > B.time)return true;

        if (A.add_cost < B.add_cost)return false;
        if (A.add_cost > B.add_cost)return true;

        if (A.to < B.to)return false;
        if (A.to > B.to)return true;

        return false;
    }

};


vector<Edge> v[101];
priority_queue<Edge, vector<Edge>, cmdstruct> pq;
int N, M, A, B, C, D, E;
void dijkstra() {

    //dist�� ����for������ �������� dist[], cnt[]�� ����ص� �ȴ�
    int dist_cost[101][101] = {0};
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist_cost[i][j] = 2134567890;

    pq.push({ 1,0,0,0,0 });
    dist_cost[1][0] = 0;

    while (!pq.empty())
    {
        Edge now = pq.top(); pq.pop();
        int nowTo = now.to;
        int nowCost = now.cost;
        int nowAdd = now.add_cost;
        int nowTime = now.time;
        int nowCnt = now.cnt;

        if (dist_cost[nowTo][now.cnt] < nowCost) continue;

        //==if(used[nowTo]==1) continue;
        for (int i = 0; i < v[nowTo].size(); i++)
        {
            Edge next = v[nowTo][i];

            next.cnt = nowCnt + 1;
            if (next.time > 10) {
                if (dist_cost[next.to][next.cnt] <= dist_cost[nowTo][nowCnt] + next.cost + (next.time - 10) * next.add_cost) continue;
                dist_cost[next.to][next.cnt] = dist_cost[nowTo][nowCnt] + next.cost + (next.time - 10) * next.add_cost;
            }
            else {
                if (dist_cost[next.to][next.cnt] <= dist_cost[nowTo][nowCnt] + next.cost) continue;
                dist_cost[next.to][next.cnt] = dist_cost[nowTo][nowCnt] + next.cost;
            }
            // cost�� �����ϴ� ������ ���������� Ư�� �������� cost������ ���� �������� cost���� �����ֱ� ����
            // ���� cost���� ���� �ϳ��� ���� ��
            pq.push({ next.to, dist_cost[next.to][next.cnt], next.add_cost, next.time, nowCnt + 1 });
            
            
            //pq.push({ next.to, next.cost, next.add_cost, next.time, nowCnt + 1 });
            ///////////////////----------
        }

    }

    //min �� Ű���
    int min = 99999999, min_index=0, check = 0;
    for (int i = 1; i <= N; i++) {
        //cout << dist_cost[N][i] << endl;
        if (min > dist_cost[N][i] && dist_cost[N][i] < 2134567890)
        {
            min = dist_cost[N][i];
            min_index = i;
            check = 1;
        }
    }
    if (check) {
        cout << min << " " << min_index+1;
    }
    else
        cout << -1;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C >> D >> E;
        v[A].push_back({ B,C,D,E });
    }

    dijkstra();

    return 0;
}


