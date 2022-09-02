#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int node, edge;
int graph[101][101];
int used[101] = { 0 };
void preorder(int now) {

    cout << now << " ";

    for (int i = node; i >= 1; i--) {
        if (graph[now][i] == 1 && used[i] == 0)
        {
            used[i] = 1;
            preorder(i);
        }
    }
}

int postused[101] = { 0 };
void postorder(int now) {

    for (int i = node; i >= 1; i--) {

        if (graph[now][i] == 1 && postused[i] == 0)
        {   
            postused[i] = 1;
            postorder(i);
        }
    }
        cout << now << " ";
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int startNode;
    cin >> node >> edge >> startNode;

    for (int i = 0; i < edge; i++) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = 1;
    }
    
    used[startNode] = 1;
    preorder(startNode);
    cout << endl;
    postused[startNode] = 1;
    postorder(startNode);
    

    return 0;
}