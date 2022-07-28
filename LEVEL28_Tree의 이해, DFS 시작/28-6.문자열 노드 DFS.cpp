#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;


string str;
int arr[10][10] = { 0 };
//int visit[10] = { 0 };

void dfs(int now) {
    cout << str[now];
    //visit[now] = 1;

    for (int next = 0; next < 8; next++) {
        if (arr[now][next] == 0) continue;
        //if (visit[next] == 1)continue;
        dfs(next);
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> str;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0);

    return 0;
}