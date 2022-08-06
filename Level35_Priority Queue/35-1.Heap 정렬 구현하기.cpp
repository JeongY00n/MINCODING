#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    priority_queue<char, vector<char>> c;
    
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        c.push(str[i]);

    while (!c.empty())
    {
        cout << c.top();
        c.pop();
   }

    return 0;
}