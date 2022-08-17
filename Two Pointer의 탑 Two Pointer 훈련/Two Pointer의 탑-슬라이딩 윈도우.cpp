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

    int t;
    int n, m;
    
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int arr[100001] = { 0 }, max_start, max_end, max_score = -2134567;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int left = 0, right = -1;
        int sum = 0;
        while (right < n) {
            if (right - left < m - 1) 
            {
                right++;
                sum += arr[right];
            }
            else
            {
                if (max_score < sum) {
                    max_score = sum;
                    max_start = left;
                    max_end = right;
                }
                sum -= arr[left];
                left++;
            }
        }

        cout << "#" << test_case << " " << max_start << " " << max_end << " " << max_score << endl;
    }



    return 0;
}


