#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;


// �˾ƾ��ϴ� ����
// 1. ���� ����� �л��� �����ϴ���
// 2. �Ʒ��� ����� �л��� �����ϴ���
// ���� �ѹ��� ���� �ʰ� ���κ��� ���� ����� �л��鿡 ���� ����(toS)
// ���κ��� ���� ����� �л��鿡 ���� ����(fromS)�� �޾Ƽ� 
// ������ ���� dfs�� ���� ���� ���Ѵ�

int N, M, X;
vector<int> fromS[100001], toS[100001];
void input() {

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        fromS[from].push_back(to);
        toS[to].push_back(from);
    }
}

// ���κ��� �Ʒ��� �� ���� �л��� �����ϴ��� Ȯ��
int downStudent = 0;
void downDFS(int now, int cnt)
{
    if (downStudent < cnt) downStudent = cnt;

    for (int i = 0; i < fromS[now].size(); i++)
    {
        int next = fromS[now][i];
        downDFS(next, cnt + 1);

    }
}

// ���κ��� ���� �� ���� �л��� �����ϴ��� Ȯ��
int upStudent = 0;
void upDFS(int now, int cnt)
{
    if (upStudent < cnt) upStudent = cnt;

    for (int i = 0; i < toS[now].size(); i++)
    {
        int next = toS[now][i];
        upDFS(next, cnt + 1);
    }
}

int main() {

    input();

    downDFS(X, 0);
    upDFS(X, 0);

    cout << upStudent + 1 << endl;
    cout << N - downStudent << endl;

    return 0;
}