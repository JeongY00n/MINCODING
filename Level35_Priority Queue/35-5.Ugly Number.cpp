#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct NODE {
    int index;
    int order;
};

struct order {
    bool operator() (NODE a, NODE b)
    {
        if (a.index < b.index)return false;
        if (a.index > b.index)return true;

        if (a.order < b.order)return false;
        if (a.order > b.order)return true;

        return false;
    }
};

priority_queue <NODE, vector<NODE>, order> Q;
priority_queue <long long, vector<long long>, greater<long long>> pq;

long long printout[100] = { 0 };
int N;
long long num = 0;
int cnt = 0, a = 0;
int Q_index = 0, Q_order = 0;
void uglyNumber() {

    while (num == pq.top()) {
        pq.pop();
    }

    num = pq.top();
    pq.pop();

    cnt++;
    if (Q.top().index == Q_index)
    {
        printout[Q.top().order] = printout[Q_order];
        Q.pop();
        a += 1;
    }
    if (cnt == Q.top().index)
    {
        Q_index = Q.top().index;
        Q_order = Q.top().order;
        printout[Q.top().order] = num;
        Q.pop();
        a += 1;
    }

    if (a == N)
        return;

    int op[3] = { 2,3,5 };

    for (int i = 0; i < 3; i++)
    {
        long long uglynumber = num * op[i];
        pq.push(uglynumber);
    }


    uglyNumber();
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> N;

    pq.push(1);

    for (int i = 0; i < N; i++)
    {
        int q;
        cin >> q;
        Q.push({ q, i });
    }


    uglyNumber();


    for (int i = 0; i < N; i++) {
        cout << printout[i] << " ";
    }
    return 0;

}