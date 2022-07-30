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
        //stack.empty() :stack이 비워졌는가?
        //stack.size() : stack에 있는 data의 개수
    {
        int data = s.top();  //stack.top() :  가장 마지막에 넣은 data(stack의 제일 위에 있는 data)를 확인
        s.pop(); //stack.pop() : 제일 마지막에 넣은 data(stack의 제일 위에 있는 data)를 제거
        cout << data;
    }

    /*
    "stack"은 어느 문제에서 쓰나?
    1. 괄호문제의 거의 대부분 ex. [{()}] , [{(})] => (o, x)
    2. 
    */







    return 0;
}

