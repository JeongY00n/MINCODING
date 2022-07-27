#include<iostream>
#include<cstring>

using namespace std;


char tree[5] = { "ABCD" };
char state[5];
char input[5];
int cnt = 0;
void run(int now) {
    if (now >= 3) {
        cnt++;
        if (strcmp(state, input) == 0)
            cout << cnt<<"¹øÂ°";
        return;
    }

    for (int i = 0; i < 4; i++) {
        state[now] = tree[i];
        run(now + 1);
        state[now] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> input;
    run(0);
    return 0;
}