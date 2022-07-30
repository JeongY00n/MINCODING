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
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (s.empty()) 
        //stack.empty() :stack�� ������°�?
        //stack.size() : stack�� �ִ� data�� ����
    {
        int data = s.top();  //stack.top() :  ���� �������� ���� data(stack�� ���� ���� �ִ� data)�� Ȯ��
        s.pop(); //stack.pop() : ���� �������� ���� data(stack�� ���� ���� �ִ� data)�� ����
        cout << data;
    }

    /*
    "stack"�� ��� �������� ����?
    1. ��ȣ������ ���� ��κ� ex. [{()}] , [{(})] => (o, x)
    2. 
    */







    return 0;
}

