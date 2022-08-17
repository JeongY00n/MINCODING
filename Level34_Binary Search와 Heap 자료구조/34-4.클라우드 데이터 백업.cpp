#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



int n;
char map[1001][1001] = { 0 };
bool find(int row) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (map[row][mid] == '#') {
            left = mid + 1;
        }
        else if (map[row][mid] == '0') {
            cout << row << " " << mid - 1;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //binary search
    //정렬 필수!
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (find(i)) {
            break;
        }
    }


    return 0;
}


