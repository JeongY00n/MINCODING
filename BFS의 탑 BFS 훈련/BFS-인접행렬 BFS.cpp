#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue> 
#include<vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N;
    cin >> N;
    int arr[10][10] = { 0 };

    for (int from = 0; from < N; from++) { 
        for (int to = 0; to < N; to++) {
            cin>>arr[from][to];
        }
    }
    
    queue<int> q;
    int used[10] = { 0 };
    q.push(0);
    used[0] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";
      
        for (int i = 1; i < N; i++) {
            if (arr[now][i] == 0)continue;
            if (used[i] == 1)continue;
            used[i] = 1;
            q.push(i);
        }
    }

    return 0;
}