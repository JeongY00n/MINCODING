#include<iostream>
using namespace std;


int path[4] = { 0 };
int n;
void run(int now)
{
    if (now >= 4) {
        for (int i = 0; i < 4; i++)
            cout << path[i];
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        path[now] = i;
        run(now + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    cin >> n;
    run(0);

    return 0;
}