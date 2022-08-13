#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int used[4] = { 0 };
int cnt = 0;
int n;
void dfs(int sum) {

    if (sum == n) {
        cnt++;
        return;
    }
    if (sum > n) {
        return;
    }
    for (int i = 1; i <= 3; i++) {
        sum += i;
        dfs(sum);
        sum -= i;
    }

    return;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;
    int num[3] = { 1,2,3 };

    dfs(0);

    cout << cnt;

    return 0;
}


