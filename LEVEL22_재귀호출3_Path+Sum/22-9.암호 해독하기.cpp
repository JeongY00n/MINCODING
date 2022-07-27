#include<iostream>
#include<cstring>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    char pass[5][10] = { "Jason","Dr.tom","EXEXI","GK12P","POW" };
    char str[10];
    cin >> str;
    int ok = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(pass[i], str) == 0)
        {
            ok = 1;
            break;
        }
    }

    if (ok)
        cout << "암호해제";
    else
        cout << "암호틀림";
    return 0;
}