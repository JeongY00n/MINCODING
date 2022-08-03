#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


struct NODE {
    int num;
    char ch;
};

bool operator<(NODE n1, NODE n2) {
    if (n1.num < n2.num) return true;
    if (n1.num > n2.num) return false;

    if (n1.ch < n2.ch) return true;
    if (n1.ch > n2.ch) return false;

     return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n; cin >> n;

    NODE arr[101];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].num >> arr[i].ch;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i].num <<" "<< arr[i].ch<<endl;
    }

    return 0;
}