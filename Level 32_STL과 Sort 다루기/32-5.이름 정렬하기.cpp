#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


bool cmd(string a, string b) {
    if (a.length() < b.length())return true;
    if (a.length() > b.length())return false;

    if (a < b) return true;
    if (a > b)return false;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    
    string arr[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, cmd);

    for (int i = 0; i < n; i++)
        cout << arr[i] <<endl;

    return 0;
}