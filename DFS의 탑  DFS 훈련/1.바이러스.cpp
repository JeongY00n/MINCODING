#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 
#include<vector>
using namespace std;




int arr[100][100] = { 0 };
int used[100] = { 0 };
int node, edge;
int cnt = 0;

void run(int now) {
    
    for (int next = 1; next <= node; next++) {
        if (arr[now][next] == 0) continue;
        if (used[next] == 1)continue;
        used[next] = 1;
        run(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> node>>edge;


    for (int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    run(1);
    for (int i = 1; i <= node; i++)
        cnt += used[i];
    cout << cnt-1;
    return 0;
}

