#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 


using namespace std;

string str;
int b = 0;
int cnt = 0;
void find(int a) {
    b = str.find('_', a);
    if (b == -1)
    {
        cnt++;
        cout << cnt << "#";
        for (int i = a; i < str.length(); i++)
            cout << str[i];
        return;
    }
    
    if (b - a > 1) {
        cnt++;
        cout << cnt << "#";
        for (int i = a; i < b; i++) {
            cout << str[i];
        }cout << endl;
        
    }a = b + 1;
        find(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    cin >> str;

    find(0);

    return 0;
}