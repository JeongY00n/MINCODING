#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int input[4][2];
    int vect[4][3] = { 0 };
    for (int i = 0; i < 4; i++)
    {
        cin >> input[i][0] >> input[i][1];
        vect[input[i][0]][input[i][1]] = 5;
    }
    

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {

            cout << vect[i][j] << " ";
        }cout << endl;
    }
    return 0;
}