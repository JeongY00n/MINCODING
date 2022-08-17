#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int perfix[100001] = { 0, };
int tree[100001] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> tree[i];
        perfix[i] = perfix[i - 1] + tree[i];
    }

    int maxfruit = -1;

    for (int i = 2; i < N; i++) {

        // 1�� �ε��� , N�� �ε��� , i�� �ε��� 
        // ������ 1���� N���� ���õɰž�
        // i �� ���� ���� �ٱ��ϰ� ���� �ڸ��� �� �� �ϳ� ����������
        // ��� ������ �ִ� �����!

        //�ٱ��ϰ� 1�� �ε����� ���
        int fruit = perfix[N - 1] + perfix[i - 1] - tree[i];
        if (fruit > maxfruit) maxfruit = fruit;

        //�ٱ��ϰ� N�� �ε����� ���
        int fruit2 = 2 * perfix[N] - perfix[i] - perfix[1] - tree[i];
        if (fruit2 > maxfruit) maxfruit = fruit2;
        //�ٱ��ϰ� i�� �ε����� ���
        int fruit3 = perfix[N - 1] - perfix[i - 1] + perfix[i] - perfix[1];
        if (fruit3 > maxfruit) maxfruit = fruit3;
    }

    //for (int i = 0; i <= N; i++) cout << perfix[i] << "\n";

    cout << maxfruit;

    return 0;
}