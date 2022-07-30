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
    q.push(5);
    q.push(2);
    q.push(7);
    q.push(4);
    q.push(1);

    while (!q.empty())
        // queue.empty() : queue가 비워졌는가?
        // queue.size() : queue에 있는 data의 개수
    {
        int data = q.front(); //queue.front() : queue 구조상 제일 먼저 나올( 제일 먼저 들어갔던)data 확인
        q.pop(); //queue.pop() : queue 구조상 제일 먼저 나올(제일 먼저 들어갔던) data 삭제

        cout << data;

    }
    return 0;
}

