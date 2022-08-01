#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int arr[6][6] = {
        0,0,1,0,7,0,
        5,0,3,0,0,0,
        0,0,0,0,0,7,
        2,0,0,0,8,0,
        0,0,9,0,0,0,
        4,0,0,7,0,0
    };
int start;
int used[6] = { 0 };
//이 문제의 경우
//cost값이 각 노드마다 필요한 cost값이 아니라
//왔다갔다 했을 때의 총 cost값이므로 배열이 아니라 int형 정수
//ex) 5->3 = 23(x) , 5->0->5->3 = 27(o)
int cost = 0;
void dfs(int now) {

    cout << now << " ";
    cout << cost << endl;
    
    for (int next = 0; next < 6; next++) {
        if (arr[now][next] == 0)continue;
        if (used[next] == 1)continue;


        used[next] = 1;
        cost += arr[now][next];
        dfs(next);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    

     cin >> start;
     used[start] = 1;
     dfs(start);
    

    return 0;
}
