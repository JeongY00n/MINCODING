#define _CRT_SECURE_NO_WARNINGS
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

    string name;
    cin >> name;
    int n;
    cin >> n;
    string food[100];
    for (int i = 0; i < n; i++) {
        cin >> food[i];
        if (food[i].find(name) == string::npos)
            cout << "X\n";
        else
            cout << "O\n";
    }

    return 0;
}