#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


void ds(string str) {
    int left = 0, right = str.length() - 1;
    int last = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (str[mid] == '#') {
            left = mid + 1;
            last = mid;
        }
        else {
            right = mid - 1;
        }
    }
    cout << (last + 1) *100 /str.length() << "%\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //binary search
    //정렬 필수!
    
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        ds(str);
    }

    return 0;
}


