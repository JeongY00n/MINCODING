#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int n, num; cin >> n;
    string order;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> order;
        if (order=="push")
        {  
            cin >> num;
            v.push_back(num);
        }
        if (order =="pop")
        {
            v.pop_back();
        }
        if(order=="printLast")
        {
            cout << v[v.size() - 1] << endl;
        }
    }
    return 0;
}