#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 
#include<stack>


using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    stack<int> s;
    string op;
    int n, data;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "push") {
            cin >> data;
            s.push(data);
        }
        else if (op == "pop") {
            if (s.empty())
                cout << -1 << endl;
            else 
            {
                cout<<s.top() << endl;
                s.pop();
            }
        }
        else if (op == "size") {
            cout << s.size() << endl;

        }
        else if (op == "empty") {
            if (s.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (op == "top") {
            if (s.empty())
                cout << -1 << endl;
            else
                cout<<s.top() << endl;
            
        }

    }

    return 0;
}

