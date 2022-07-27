#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 
#include <math.h>


int cnt = 0;
using namespace std;

int fail = 0, pass = 0;
void findpass(string input)
{
    if (input.find("pass") == string::npos)
        return;
    else
    {
        input.replace(input.find("pass"), 4, "0000");
        pass++;
        findpass(input);
    }
}
void findfail(string input)
{
    if (input.find("fail") == string::npos)
        return;
    else
    {
        input.replace(input.find("fail"), 4, "0000");
        fail++;
        findfail(input);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if ('A' <= input[i] && input[i] <= 'Z')
            input[i] = input[i] + 32;
    }

    if (input.find("pass") == string::npos)
        ;
    else
    {
        findpass(input);

    }

    if (input.find("fail") == string::npos)
        ;
    else
    {
        findfail(input);
    }

    cout << trunc((pass/(float)(pass+fail))*100)<<"%";

    return 0;
}