#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 

using namespace std;

string str;
int ok = 0;
int idx = 0;

void check_str() {
    int check[123] = { 0 };
    for (int i = idx+1; i <= str.find('>'); i++) {

        if (check[str[i]] == 1)
        {
            cout << "X";
            ok = 1;
            idx = i;
            return;
        }

        if (str[i] == '>')
        {
            idx = i;
            return;
        }
        cout << str[i] << endl;
        check[str[i]] = 1;

    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        idx = 0;
        ok = 0;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (ok)
                break;
            cout << idx<<endl;
            idx = str.find('<', idx);

            if (idx == string::npos)
                ;
            else
            {
                int de = 1;
                check_str();
            }
        }

        if (!ok)
            cout << "O";
    }

    return 0;
}

