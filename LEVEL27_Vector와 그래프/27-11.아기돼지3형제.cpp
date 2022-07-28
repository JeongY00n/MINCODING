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

    char home[4][4] = { 0 };
    int input[3][2];
    int wall[8][2] = { -1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1 };

    //집 위치 입력
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 2; col++) {
            cin >> input[row][col];
            
        }home[input[row][0]][input[row][1]] = '#';
    }

    
    for (int row = 0; row < 3; row++) {
        for (int i = 0; i < 8; i++) {
            int y = input[row][0] + wall[i][0];
            int x = input[row][1] + wall[i][1];
            if (0 <= y && y < 4 && 0 <= x && x < 4) {
                home[y][x] = '@';
            }
        }
    }
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (home[row][col] == 0)
                cout << '_';
            else
                cout << home[row][col];
        }cout << endl;
    }

    return 0;
}