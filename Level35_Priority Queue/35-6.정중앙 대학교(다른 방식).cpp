#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    priority_queue<int> lheap;
    priority_queue<int, vector<int>, greater<int>> rheap;

    int mid = 500;

    int n;
    int a, b;

    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a >> b;

        if (a > mid)
            rheap.push(a);
        else
            lheap.push(a);
        if (b > mid)
            rheap.push(b);
        else
            lheap.push(b);


        if (lheap.size() > rheap.size())
        {
            rheap.push(mid);
            mid = lheap.top();
            lheap.pop();
        }
        else
        {
            lheap.push(mid);
            mid = rheap.top();
            rheap.pop();
        }

        cout << mid << endl;
    }
  
    return 0;
}