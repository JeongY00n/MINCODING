#include<iostream>
using namespace std;


int cnt = 0, n, level;
char str[4] = { "ABC" }, state[10];
void run(int now) {
    if (now >= n) {
        cnt++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (state[now - 2] == str[i] && state[now - 1] == str[i] && now >= 2)
            continue;
        state[now] = str[i];
        /*
        ���� ��ư� �� �ʿ� ���� �׳� ���ӵ� �� �� ���ڸ� Ȯ���ϱ�..
        used[i] *= -1;*/
        run(now + 1);
        state[now] = 0;
        /*used[i] *= -1;*/
    }


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    cin >> n;
    run(0);
    cout << cnt;

    return 0;
}