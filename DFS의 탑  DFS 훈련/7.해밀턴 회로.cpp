#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 
#include<vector>
using namespace std;



int n;
int arr[12][12] = { 0 };
int used[12] = { 0 };
int cost = 0, MIN = 1000;
int level;
void run(int now) {

    if (level >= n - 1) {
        cost += arr[now][0];
        if (cost == 84)
            int de = 1;
        //########1�� ���������� ���� ����!
        if (arr[now][0] != 0 && MIN > cost)
            MIN = cost;
        cost -= arr[now][0];
        return;
    }


    for (int next = 1; next < n; next++) {
        if (arr[now][next] == 0) continue;
        if (used[next] == 1) continue;

        used[next] = 1;
        cost += arr[now][next];
        level++;
        run(next);

        //�����鼭 ���, �湮���, �湮 ��� ���� ����
        cost -= arr[now][next];
        level--;
        used[next] = 0;
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
    int dw = 1;
    run(0);
    cout << MIN;

    return 0;
}

