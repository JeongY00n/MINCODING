#include<iostream>
using namespace std;



char arr[3] = { 'A','B','C' };
void run(int now)
{
    if (now > 2) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        cout << arr[now] << arr[i] << endl;

    }run(now + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    run(0);

    return 0;
}