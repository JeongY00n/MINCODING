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

    int n, m;
    int arr[10001] = { 0 };

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0, right = -1;
    int sum = 0;
    int cnt = 0;
    while (right <= n) {
        if (sum < m) {
            right++;
            sum += arr[right];
        }
        else if (sum >= m) {
            if(sum == m)
                cnt++;
            sum -= arr[left];
            left++;
        }

    }
    
    cout << cnt;


    return 0;
}


