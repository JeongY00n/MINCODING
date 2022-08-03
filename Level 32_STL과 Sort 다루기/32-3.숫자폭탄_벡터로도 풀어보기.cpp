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

    int n, k = 0; cin >> n;
    int bomb[100];

    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (k >= 2 && a == bomb[k - 1] && a == bomb[k - 2])
        {
            k -= 2;
            continue;
        }
        bomb[k++] = a;
    }
    sort(bomb, bomb + k);
 
    for (int i = 0; i < k; i++)
        cout << bomb[i] << " ";
        
    


    return 0;
}