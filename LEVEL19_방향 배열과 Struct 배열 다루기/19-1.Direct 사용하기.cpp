#include<iostream>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int arr[3][3] = {
    {3, 5, 4},
    {1, 1, 2},
    {1, 3, 9}
    }, x, y, sum = 0;
    cin >> y >> x;
    for (int row = -1; row <= 1; row++) {
        if (y + row < 0 || y + row >= 4)
            continue;
        sum += arr[y + row][x];
    }
    for (int col = -1; col <= 1; col++) {
        if (x + col < 0 || x + col >= 4)
            continue;
        sum += arr[y][x + col];
    }
    cout << sum - 2 * arr[y][x];
    return 0;
}