#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


/// <summary>
/// long long 신경써주기!!!!!!!!!
/// </summary>

long long n, m;
vector<long long> Time;
void ds() {
    long long left = 0, right = Time.back() * m;
    long long last;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for (int i = 0; i < Time.size(); i++) {
            cnt += (mid / Time[i]);
        }
        if (m <= cnt) {
            right = mid - 1;
            last = mid;
        }
        else if (m > cnt) {
            left = mid + 1;
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
    
    
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        Time.push_back(t);
    }
    //내림차순
    sort(Time.rbegin(), Time.rend());
    ds();
    

    return 0;
}


