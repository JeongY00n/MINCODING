#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int n;
vector<int> map;
int k;


//void ds() {
//    int i = 0;
//    int left = 0, right = n - 1;
//    while (i<k) {
//        if (num[i] > map[left]) {
//            left++;
//        }
//        else if (num[i] < map[left]) {
//            i++;
//            cout << "X";
//            left = 0;
//        }
//        else {
//            i++;
//            cout << "O";
//            left = 0;
//        }
//    }
//}

void ds(int num) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (num > map[mid]) {
            left = mid + 1;
        }
        else if (num < map[mid]) {
            right = mid - 1;
        }
        else {
            cout << "O";
            return;
        }
    }
    cout << "X";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //binary search
    //정렬 필수!
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        map.push_back(num);
    }
    sort(map.begin(), map.end());

    int num[1001];
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> num[i];
        ds(num[i]);
    }
    // ds();

    

    return 0;
}


