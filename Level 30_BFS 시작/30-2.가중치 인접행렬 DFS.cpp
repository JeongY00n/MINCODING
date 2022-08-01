#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int arr[6][6] = {
        0,0,1,0,7,0,
        5,0,3,0,0,0,
        0,0,0,0,0,7,
        2,0,0,0,8,0,
        0,0,9,0,0,0,
        4,0,0,7,0,0
    };
int start;
int used[6] = { 0 };
//�� ������ ���
//cost���� �� ��帶�� �ʿ��� cost���� �ƴ϶�
//�Դٰ��� ���� ���� �� cost���̹Ƿ� �迭�� �ƴ϶� int�� ����
//ex) 5->3 = 23(x) , 5->0->5->3 = 27(o)
int cost = 0;
void dfs(int now) {

    cout << now << " ";
    cout << cost << endl;
    
    for (int next = 0; next < 6; next++) {
        if (arr[now][next] == 0)continue;
        if (used[next] == 1)continue;


        used[next] = 1;
        cost += arr[now][next];
        dfs(next);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    

     cin >> start;
     used[start] = 1;
     dfs(start);
    

    return 0;
}
