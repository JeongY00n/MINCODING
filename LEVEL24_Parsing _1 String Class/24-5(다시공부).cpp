#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 



int cnt = 0;
using namespace std;

void find(string input)
{
    if (input.find("MCD") == string::npos)
        return;
    else
    {
        input.replace(input.find("MCD"), 3, "000");
        cnt++;
        find(input);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string input[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> input[i];
        if (input[i].find("MCD") == string::npos)
            ;
        else
        {
            find(input[i]);
        }
    }
    cout << cnt;

    return 0;
}