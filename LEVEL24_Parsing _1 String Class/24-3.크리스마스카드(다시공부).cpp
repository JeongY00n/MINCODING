#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 

using namespace std;

string card = "CHRISTMAS";
int n, cnt = 0;
string str[100];
string ok;
int path[100];
void run(int now) {
    if (path[0] == 2 && path[1] == 3)
        int de = 1;
    if (now >= n)
        return;

    if (card.empty())
    {
        cnt++;
        return;
    }

    int idx;


    for (int i = 0; i < n; i++) {
        if (card.find(str[i]) == string::npos)
            ;
        else {
            idx = card.find(str[i]);
            card.erase(idx, str[i].length());
            path[now] = i;
            run(now + 1);
            path[now] = -1;
            card.insert(idx, str[i]);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];

    }

    run(0);
    cout << cnt;
    return 0;
}
