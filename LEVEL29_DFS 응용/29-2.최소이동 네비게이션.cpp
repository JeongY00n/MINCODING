#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 
#include<vector>
using namespace std;




int A, B;
int arr[7][7] = {
    0,0,0,0,0,0,0,
    0,0,0,1,0,1,1,
    0,1,0,0,1,0,0,
    0,0,0,0,0,1,0,
    0,1,0,0,0,0,0,
    0,1,0,0,0,0,0,
    0,0,0,0,0,0,0
};
vector<int> path;
int used[10] = { 0 };
int check = 0;

void run(int now) {
    if (now == B)
    {
        cout << path.size();
        check = 1;
        return;
    }

    for (int next = 1; next < 7; next++) {
        if (arr[now][next] == 0)continue;
        if (used[next] == 1)continue;
        path.push_back(next);
        used[next] = 1;
        run(next);
        path.pop_back();
        used[next] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> A >> B;
    
    
    run(A);
    if (!check)
        cout << "0";

    return 0;
}

