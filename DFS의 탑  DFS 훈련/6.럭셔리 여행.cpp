#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 
#include<vector>
using namespace std;



int n;
int arr[100][100] = { 0 };
int start, last;
int MAX = 0, MIN = 1000, cost = 0;
int used[100] = { 0 };
void run(int now) {

    if (now == last) {
        if (MAX < cost)
            MAX = cost;
        if (MIN > cost)
            MIN = cost;
        return;
    }
    used[now] = 1;
    for (int next = 0; next < n; next++) {
        if (arr[now][next] == 0) continue;
        if (used[next] == 1) continue;
        cost += arr[now][next];
        run(next);
        cost -= arr[now][next];
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
    cin >> start >> last;
    run(start);
    cout << MIN << "\n" << MAX;

    return 0;
}

