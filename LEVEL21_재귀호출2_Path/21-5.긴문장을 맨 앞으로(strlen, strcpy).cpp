#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    char str[3][11];
    cin >> str[0] >> str[1] >> str[2];
    int len[3], max=0, max_index;
    for (int i = 0; i < 3; i++) {
        len[i] = strlen(str[i]);
        if (len[i] > max) {
            max = len[i];
            max_index = i;
        }
    }
    char change[11];
    strcpy(change, str[0]);
    strcpy(str[0], str[max_index]);
    strcpy(str[max_index], change);
    cout << str[0] << endl;
    cout << str[1] << endl;
    cout << str[2] << endl;
    return 0;
}