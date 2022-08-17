#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


void ds(int num) {
    int left = 0, right = num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //binary search
    //정렬 필수!
    
    int num;
    cin >> num;
    int left = 1;
    long long right = 1e8;
    int last = -1;
    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (num < mid * mid)
        {
            right = mid - 1;
        }
        else if (num >= mid * mid)
        {
            left = mid + 1;
            last = mid;
        }


    }
    cout << last;
    return 0;
}


