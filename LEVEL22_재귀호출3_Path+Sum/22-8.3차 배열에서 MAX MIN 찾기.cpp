#include<iostream>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int arr[3][2][2] = { {{2,4},{1,5}},{{2,3},{3,6}},{{7,3},{1,5}} };

    int a, max = 0, min = 100;
    cin >> a;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (max < arr[a][i][j]) {
                max = arr[a][i][j];
            }
            if (min > arr[a][i][j]) {
                min = arr[a][i][j];
            }
        }
    }
    cout << "MAX=" << max << endl;
    cout << "MIN=" << min << endl;
    return 0;
}