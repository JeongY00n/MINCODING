#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;



int arr[10][10] = { 0 };
int visit[10] = { 0 };
int new_arr[4] = { 0 };
int n, level = 0;
void dfs(int now) {
    new_arr[level] = now;
    if (level >= 2) {
        cout << new_arr[0]<<" " << new_arr[1] << " " << new_arr[2] << endl;
        
        return;
    }

    for (int next = 0; next < n; next++) {
        if (arr[now][next] == 0) continue;
        level++;
        dfs(next);
        new_arr[level] = 0;
        level--;
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