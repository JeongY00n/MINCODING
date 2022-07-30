#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 

using namespace std;




int n;
int arr[100][100];
void run(int now) {
    cout << now << " ";

    for (int next = 0; next < n; next++) {
        if (arr[now][next] == 0)continue;
        run(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

     cin >> n;
    
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> arr[row][col];
        }
    }
    run(0);


    return 0;
}

