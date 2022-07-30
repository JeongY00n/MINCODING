#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 
#include<stack>
#include<queue>

using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    
    queue<int> q;
    int n, data;
    string op;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "push") {
            cin >> data;
            q.push(data);
        }
        else if (op == "pop") {
            if (q.empty())
            {
                cout << -1 << endl;
                continue;
            }
            int out = q.front();
            q.pop();
            cout << out << endl;
        }
        else if (op == "size") {
            cout << q.size()<<endl;
        }
        else if (op == "empty") {
            if (q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (op == "front") {
            if (q.empty())
            {
                cout << -1 << endl;
                continue;
            }
            int out = q.front();
            cout << out << endl;
        }
        else if (op == "back") {
            if (q.empty())
            {
                cout << -1 << endl;
                continue;
            }
            int out = q.back();
            cout << out << endl;
        }
    }

    return 0;
}

