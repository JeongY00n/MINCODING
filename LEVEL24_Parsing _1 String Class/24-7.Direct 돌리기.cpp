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

    string music;;
    cin >> music;
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < c; i++) {
        cout << music[i];
    }

    return 0;
}