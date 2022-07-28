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

    char family[9] = { "ABCDEFGH" };
    int line[8][8] = {
        0,1,1,0,0,0,0,1,
        0,0,0,0,0,0,0,0,
        0,0,0,1,1,0,1,0,
        0,0,0,0,0,1,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
    };
    char name; cin >> name;
    int int_name = int(name - 'A');
    int OK = 0;
    for (int i = 0; i < 8; i++) {
        if (line[i][int_name] == 1) {
            for (int j = 0; j < 8; j++) {
                if (j != int_name && line[i][j] == 1)
                    cout << family[j]<<" ";
            }
            OK = 1;
            break;
        }
    }
    if (!OK)
        cout << "¾øÀ½";

    return 0;
}