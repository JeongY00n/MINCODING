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
        // queue.empty() : queue�� ������°�?
        // queue.size() : queue�� �ִ� data�� ����
    {
        int data = q.front(); //queue.front() : queue ������ ���� ���� ����( ���� ���� ����)data Ȯ��
        q.pop(); //queue.pop() : queue ������ ���� ���� ����(���� ���� ����) data ����

        cout << data;

    }
    return 0;
}

