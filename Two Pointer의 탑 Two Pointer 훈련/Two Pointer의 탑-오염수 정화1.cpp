#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int n;
    cin >> n;
    int arr[100001] = { 0 };

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int left = 0, right = n - 1, min_start, min_end, min = 21345676789090;


    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) <= min) {
            if (abs(sum) == min)
            {
                int first = abs(arr[min_start]) + abs(arr[min_end]);
                int second = abs(arr[left]) + abs(arr[right]);

                if (first < second)
                {
                    min = abs(sum);
                    min_start = left;
                    min_end = right;
                }
            }
            else {
                min = abs(sum);
                min_start = left;
                min_end = right;
            }
        }

        if (sum > 0) {
            right--;
        }
        else if (sum < 0) {
            left++;
        }
        if (sum == 0)
            break;
    }

    if (arr[min_start] < arr[min_end])
        cout << arr[min_start] << " " << arr[min_end];
    else
        cout << arr[min_end] << " " << arr[min_start];
    return 0;
}


