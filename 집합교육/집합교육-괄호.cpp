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
    //DAT - index : �ݴ� ��ȣ ����
    //    - value : �ش��ϴ� ��ȣ ���� ����
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
        else {  //ch : �ݴ� ��ȣ
            if (s.empty())
            {
                cout << 0;
                return 0;
            }
            if (pairChar[ch] == s.top())  //pairChar[ch] -> ch�� �ݾƾ� �ϴ� ���� ��ȣ
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
    cout << s.empty(); // stack�� �� ������� ������� ��ȣ���� ���� �� �ݾҴ��� Ȯ��
    
    return 0;
}

