#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;



//트리 Tree-> 임의 점 두개를 연결하는 가장 짧은 경로가 유일하다
//NODE = n개, EDGE = n-1개
//첫 NODE를 제외한 나머지 NODE들은 EDGE를 가지고 있으므로
//EDGE의 개수는 n-1개가 된다


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int num; cin >> num;
    int arr[10][10] = { 0 };
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "boss:";
    for (int i = 0; i < num; i++) {
        if (arr[i][0] == 1)
            cout << i << " ";
    }

    cout << "\nunder:";
    for (int i = 0; i < num; i++) {
        if (arr[0][i] == 1)
            cout << i << " ";
    }

    return 0;
}