#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Heap {
    char from;
    char to;
    int cost;
};

struct order {
    bool operator() ( Heap a, Heap b )
    {
        if (a.cost > b.cost)return false;
        if (a.cost < b.cost)return true;

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n; cin >> n;
    priority_queue<Heap, vector<Heap>, order> q;

    for (int from = 0; from < n; from++) {
        for (int to = 0; to < n; to++) {
            int cost;
            cin >> cost;

            q.push({ char(from + 'A'), char(to + 'A'), cost });
        }
    }

    for (int i = 0; i < 3; i++) {
        Heap now = q.top();
        cout << now.from << "-" << now.to << " " << now.cost << endl;
        q.pop();
    }

    return 0;
}