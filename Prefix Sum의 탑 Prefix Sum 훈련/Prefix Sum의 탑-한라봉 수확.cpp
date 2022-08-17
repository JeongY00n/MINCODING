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

        // 1번 인덱스 , N번 인덱스 , i번 인덱스 
        // 어차피 1번과 N번은 선택될거야
        // i 번 잡은 다음 바구니가 있을 자리를 셋 중 하나 선택해주자
        // 경우 나눠서 최댓값 기록해!

        //바구니가 1번 인덱스인 경우
        int fruit = perfix[N - 1] + perfix[i - 1] - tree[i];
        if (fruit > maxfruit) maxfruit = fruit;

        //바구니가 N번 인덱스인 경우
        int fruit2 = 2 * perfix[N] - perfix[i] - perfix[1] - tree[i];
        if (fruit2 > maxfruit) maxfruit = fruit2;
        //바구니가 i번 인덱스인 경우
        int fruit3 = perfix[N - 1] - perfix[i - 1] + perfix[i] - perfix[1];
        if (fruit3 > maxfruit) maxfruit = fruit3;
    }

    //for (int i = 0; i <= N; i++) cout << perfix[i] << "\n";

    cout << maxfruit;

    return 0;
}