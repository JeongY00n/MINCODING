#include <iostream>
#include<queue>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int arr[11][11] = { 0, };

    int cntNode, cntEdge, cntCoin;
    cin >> cntNode >> cntEdge >> cntCoin;
    for (int i = 0; i < cntEdge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from][to] = cost;
        arr[to][from] = cost;
    } // 1. 그래프 구성

    int used[11] = { 0, };
    int cost[11] = { 0 };

    // 2. queue생성
    queue<int> q;

    // 3. 시작점 세팅
    q.push(0);

    // 4~6단계 반복
    while (!q.empty()) {
        // 4. now꺼내기
        int now = q.front();
        q.pop();

        // 5. now->next찾기
        for (int next = 1; next < cntNode; next++)
        {
            if (arr[now][next] == 0) continue;
            if (used[next] == 1) continue; // 들렸던 기록이 있으면 무시
           
            
             // 6. next를 queue에 추가
            used[next] = 1; // now는 들렸다.
            cost[next] = cost[now] + arr[now][next];
            q.push(next);
        }
    }
    for (int i = 1; i < cntNode; i++) {
        
        if (cntCoin < cost[i]) continue;
        if (used[i] == 0) continue; //0번에서부터 갈 수 있는지
        cout << i << " ";
    }

    return 0;
}