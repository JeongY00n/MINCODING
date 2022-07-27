#include<iostream>
using namespace std;



char arr[10];
int n;
void run(int now)
{
    if (now == n)
    {
        cout << arr << endl;
        return;
    }

    for (int x = 0; x < 4; x++) {
        if (x == 0)
            arr[now] = 'B';
        else if (x == 1)
            arr[now] = 'G';
        else if (x == 2)
            arr[now] = 'T';
        else if (x == 3)
            arr[now] = 'K';

        run(now + 1);
        arr[now] = 0;
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