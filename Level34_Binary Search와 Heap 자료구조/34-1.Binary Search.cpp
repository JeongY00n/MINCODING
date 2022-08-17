#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //binary search
    //정렬 필수!

    int arr[11] = { 4,4,5,7,8,10,20,22,23,24 };
    int ans, mid ;
    cin >> ans;
    int left = 0, right = 10;
    int ok = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] < ans) {
            left = mid + 1;
        }
        else if (arr[mid] > ans) {
            right = mid - 1;
        }
        else
        {
            cout << "O";
            ok = 1;
            break;
        }
    }
    if (!ok)
        cout << "X";

    return 0;
}


