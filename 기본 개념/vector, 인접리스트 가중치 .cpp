#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 
#include<vector>

using namespace std;


struct Edge {
    int to;
    int cost;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<Edge> v[10];

    //vector<vector<Edge>>; // ���;ȿ� ����


    for (int i = 0; i < 10; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to,cost });
    }

    //3������ ������ ���� ������ �ϳ� �����´�
    //v[3][0] <- �����ִ� ����
    //�����ִ� ������ �Ʒ��� ���� Ǯ����
    Edge edge = v[3][0];
    int to = edge.to;
    int cost = edge.cost;

    return 0;
}

