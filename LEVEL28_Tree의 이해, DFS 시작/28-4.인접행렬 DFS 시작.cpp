#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;


int arr[10][10] = { 0 };
int visit[10] = { 0 };
int n;
void dfs(int now) {
    if (visit[now] == 1)
        return;
    visit[now] = 1;
    cout << now<<" ";
    for (int next = 0; next <= n; next++) {

        if (arr[now][next] == 0) continue;

        dfs(next);
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

     cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0);

    return 0;
}