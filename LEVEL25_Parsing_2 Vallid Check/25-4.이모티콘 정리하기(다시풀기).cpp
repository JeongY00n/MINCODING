#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 


using namespace std;

string str;
int b = 0;
void find1(int a) {
    b = str.find('(', a);
    if (b == -1)return;
    if (str[b + 1] == '(' && b!=str.length())
    {
        str.erase(b, 1);
        find1(b);
    }
    else {
        find1(b + 1);
    }

}
void find2(int a) {
    b = str.find(')', a);
    if (b == -1)return;
    if (str[b + 1] == ')' && b != str.length())
    {
        str.erase(b, 1);
        find2(b);
    }
    else {
        find2(b + 1);
    }

}
void find3(int a) {
    b = str.find("^^^", a);
    if (b == -1)return;
    str.erase(b, 1);
    find3(b);
}
void find4(int a) {
    b = str.find('^', a);
    if (b == -1)return;
    if (b != str.length()) {
        if (str[b + 1] != '_' && str[b + 1] != '(' && str[b + 1] != ')' && str[b + 1] != '^')
        {
            str[b + 1] = '_';
        }
    }
    find4(b + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    cin >> str;
    find1(0);
    find2(0);
    find3(0);
    find4(0);
    cout << str;
    return 0;
}