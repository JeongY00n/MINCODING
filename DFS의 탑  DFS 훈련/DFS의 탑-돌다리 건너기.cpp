#include<iostream>
#include<vector>
#include<queue>
using namespace std;

string str;
//vector<char> bridge[2];
string bridge[2];
int cnt = 0;
void dfs(int n, int y, int x) {

    if (str.length() == n)
    {
        cnt++;
        return;
    }

    for (x; x < bridge[0].length(); x++) {
        if (str[n] != bridge[y][x]) continue;
        if (y == 0)
            dfs(n+1, 1, x+1);
        else
            dfs(n+1, 0, x+1);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    
    cin >> str;

    cin >> bridge[0];
    cin >> bridge[1];

    dfs(0, 0, 0);
    dfs(0, 1, 0);

    cout << cnt;

    return 0;
}