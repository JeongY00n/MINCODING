#include<iostream>
#include<cstring>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    char str[3][11];
    int cnt = 0;
    cin >> str[0] >> str[1] >> str[2];
    if (strcmp(str[0], str[1]) == 0 && strcmp(str[0], str[2]) == 0)
        cout << "WOW";
    else if (strcmp(str[0], str[2]) == 0)
        cout << "GOOD";
    else if (strcmp(str[0], str[1]) == 0)
        cout << "GOOD";
    else if (strcmp(str[2], str[1]) == 0)
        cout << "GOOD";
    else
        cout << "BAD";

    /*
    if (strcmp(str[0], str[1]) == 0 && strcmp(str[0], str[2]) == 0)
        cout << "WOW";
    else if (strcmp(str[0], str[2]) != 0 &&strcmp(str[0], str[1]) != 0 && strcmp(str[2], str[1]) != 0)
        cout << "BAD";
    else
        cout << "GOOD";
    */
    return 0;
}