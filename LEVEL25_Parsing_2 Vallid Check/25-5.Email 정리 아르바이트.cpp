#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    string email;
    cin >> email;
    int check = 1;
    for (int len = 0; len < email.length(); len++) {

        if (len == 0)
            cout << "[#";

        if (email[len] == '.')
        {
            check = 0;
            len++;
        }
        else if (email[len] == '|')
        {
            check = 1;
            len++;
            cout << "\n[#";
        }
        else if (email[len] == '@')
        {
            cout << "] ";
            len++;
        }


        if (check)
            cout << email[len];
    }


    return 0;
}

