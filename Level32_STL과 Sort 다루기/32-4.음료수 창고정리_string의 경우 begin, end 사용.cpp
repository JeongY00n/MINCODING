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

    
    string arr[5];
    int line1, line2;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    cin >> line1 >> line2;

    //string의 경우는 begin, end사용
    sort(arr[line1].begin(), arr[line1].end());
    sort(arr[line2].begin(), arr[line2].end());

    for (int i = 0; i < 5; i++) {
        cout << arr[i][0] << " ";
    }

    return 0;
}