#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;


// 알아야하는 것이
// 1. 위에 몇명의 학생이 존재하는지
// 2. 아래에 몇명의 학생이 존재하는지
// 값을 한번에 받지 않고 본인보다 낮은 등수의 학생들에 대한 정보(toS)
// 본인보다 높은 등수의 학생들에 대한 정보(fromS)로 받아서 
// 각각에 대해 dfs를 돌려 답을 구한다

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

// 본인보다 아래에 몇 명의 학생이 존재하는지 확인
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

// 본인보다 위에 몇 명의 학생이 존재하는지 확인
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