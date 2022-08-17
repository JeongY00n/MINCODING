#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int n, k;
vector<long long> v;
long long sum = 0;
void ds() {
    long long left = 0, right = sum;
    long long last = sum;
    while (left <= right && right!=1) {
        long long mid = (left + right) / 2;
        int cnt = 0;

        for (int i = 0; i < v.size(); i++) {
            cnt += (v[i] / mid);
        }
        if (k <= cnt) {
            left = mid + 1;
            last = mid;
        }
        else if (k > cnt) {
            right = mid - 1;
        }
    }
    cout << last;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //binary search
    //정렬 필수!
    
    
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    sort(v.begin(), v.end());
    sum /= k;
    ds();

    return 0;
}


