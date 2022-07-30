#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 
#include<stack>


using namespace std;

int MAX = 0, sum = 0, max_y, max_x;
int image[4][4];

void rectSum(int y, int x) {
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            sum += image[y + row][x + col];
        }
    }
    if (MAX < sum)
    {
        MAX = sum;
        max_y = y; max_x = x;
    }
    sum = 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            cin >> image[row][col];
        }
    }
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 2; col++) {
            rectSum(row, col);
        }
    }

    cout << "(" << max_y << "," << max_x << ")";
    return 0;
}

