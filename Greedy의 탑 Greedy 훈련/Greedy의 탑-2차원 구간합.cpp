#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int MAP[1010][1010];
int prefix[1010][1010];
int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> MAP[i][j];

    // prefix����
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + MAP[i][j];
            //             ���� ���簢��      ���� ���簢��   ��������� ��ġ�� ���簢��   ������ ��
        }

    // query
    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1] << "\n";
    }

    return 0;
}