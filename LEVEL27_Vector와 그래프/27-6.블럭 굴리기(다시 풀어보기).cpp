#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;

int cube[3][3] = { {0,5,4},{3,0,0},{0,0,1} };
int result[3][3] = { {0,5,4},{3,0,0},{0,0,1} };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    
    int input; cin >> input;
    for (int i = 1; i <= input; i++) {
        if (i % 4 == 0) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    result[row][col] = cube[row][col];
                }
            }
        }
        else if (i%4==1) {
            for (int col = 0; col < 3; col++) {
                for (int row = 2; row >= 0; row--) {
                    result[col][2-row] = cube[row][col];
                }
            }
            
        }
        else if (i % 4 == 2) {
            for (int row = 2; row >= 0; row--) {
                for (int col = 2; col >= 0; col--) {
                    result[2 - row][2 - col] = cube[row][col];
                }
            }
        }
        else if (i % 4 == 3) {
            for  (int col = 2; col >= 0; col--){
                for (int row = 0; row < 3; row++) {
                    result[2 - col][row] = cube[row][col];
                }
            }
        }

    }

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (result[row][col] == 0) {
                cout << '_';
                continue;
            }
            cout << result[row][col];
        }cout << endl;
    }
    return 0;
}