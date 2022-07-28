#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int map[5][4] = { 0 };
    int new_map[5][4] = { 0 };
    int ok = 0, k = 4;
    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) 
            cin >> map[i][j];
    }


   
    //new_map 사용하지말고 재정렬방법으로 다시 생각해보기
    for (int i = 4; i >=0; i--) {
        ok = 0;
        for (int j = 0; j < 4; j++) {
            if (map[i][j] == 0)
            {
                ok = 1;
                break;
            }
        }
        if (ok) {
            for (int j = 0; j < 4; j++) {
                new_map[k][j]= map[i][j];
            }
            k--;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cout << new_map[i][j]<< " ";
        }cout << endl;
    }


    return 0;
}