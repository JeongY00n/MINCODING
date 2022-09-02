#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tree[1001][2];
int N;

int used1[1001] = { 0 };
void dfs1(int now) {
    for (int i = 0; i < 2; i++) {
        if (tree[now][i] > 0 && used1[tree[now][i]] == 0) 
        {

            used1[tree[now][i]] = 1;
            dfs1(tree[now][i]);
        }
        if (i == 0)
        {
            cout << now << " ";
        }
        
    }
}

int used2[1001] = { 0 };
void dfs2(int now) {

    cout << now << " ";

    for (int i = 0; i < 2; i++) {
        if (tree[now][i] > 0 && used2[tree[now][i]] == 0)
        {
            used2[tree[now][i]] = 1;
            dfs2(tree[now][i]);
        }
    }

}

int used3[1001] = { 0 };
void dfs3(int now) {
    for (int i = 0; i < 2; i++) {
        if (tree[now][i] > 0 && used3[tree[now][i]] == 0)
        {
            used3[tree[now][i]] = 1;
            dfs3(tree[now][i]);
        }
    }

    cout << now << " ";

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> N;
    for (int i = 0; i < N; i++) {
        int from, left, right;
        cin >> from >> left >> right;
        tree[from][0] = left;
        tree[from][1] = right;
    }

    dfs1(1);
    cout << endl;

    dfs2(1);
    cout << endl;

    dfs3(1);
    cout << endl;


    return 0;
}