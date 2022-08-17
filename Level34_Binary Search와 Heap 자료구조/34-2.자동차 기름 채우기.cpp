#include<iostream>
#include<vector>
#include<queue>
using namespace std;

string str;
void bs() {

    int left = 0, right = str.length()-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if(left == 9) {
            cout << 100 << "%";
            return;
        }
        if (right == 0) {
            cout << 0 << "%";
            return;
        }
        else if (str[mid] == '#') {
            left = mid + 1;
            
        }
        else if (str[mid] == '_') {
            cout << (mid - 1) * 10 << "%";
            return;
        }
    }


}
/*
int maxIndex = -1;
void bs(int left, int right) {

    if (left > right) return;

    int mid = (left + right) / 2;
    if (str[mid] == '#' && maxIndex < mid) maxIndex = mid;

    if (left == right) return;

    if (str[mid] == '_') bs(left, mid);
    if (str[mid] == '#') bs(mid + 1, right);

}

*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //binary search
    //정렬 필수!

    cin >> str;
    bs();
    // bs(0, 9);

    return 0;
}


