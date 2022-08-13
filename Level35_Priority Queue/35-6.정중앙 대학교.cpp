#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    priority_queue<int, vector<int>, greater<int>> q;
    q.push(500);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {

        vector<int> num[100];
        int score1, score2;

        cin >> score1 >> score2;

        q.push(score1);
        q.push(score2);
        
        int now=0;
        for (int j = 0; j < (i*2 + 1) / 2; j++)
        {
            now = q.top();
            q.pop();
            num[j].push_back(now);
        }
        cout << q.top() << endl;;
        for (int j = 0; j < (i*2 + 1) / 2; j++)
        {
            now = num[j].front();
            q.push(now);
        }

    }



    return 0;
}