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
    
    
    stack<char> s;
    char pairChar[255];
    //DAT - index : 닫는 괄호 문자
    //    - value : 해당하는 괄호 여는 문자
    pairChar[')'] = '(';
    pairChar['}'] = '{';
    pairChar[']'] = '[';
    
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            s.push(ch);
        }
        else {  //ch : 닫는 괄호
            if (s.empty())
            {
                cout << 0;
                return 0;
            }
            if (pairChar[ch] == s.top())  //pairChar[ch] -> ch가 닫아야 하는 여는 괄호
            {
                s.pop();
            }
            else
            {
                cout << 0;
                return 0;
            }
        }
        
    }
    cout << s.empty(); // stack이 잘 비워져서 열어놨던 괄호들을 전부 잘 닫았는지 확인
    
    return 0;
}

