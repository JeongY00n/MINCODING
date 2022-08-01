#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int arr[6][6] = {
        0,0,1,1,0,1,
        0,0,0,1,1,1,
        0,0,0,0,1,1,
        0,0,0,0,0,0,
        1,0,0,0,0,1,
        0,0,0,0,0,0
    };
int start;
int used[6] = { 0 };
void dfs(int now) {

    cout << now << " ";
    used[now] = 1;

    for (int next = 0; next < 6; next++) {
        if (used[next] == 1)continue;
        if (arr[now][next] == 0)continue;

        dfs(next);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    

     cin >> start;
     dfs(start);
    

    return 0;
}
