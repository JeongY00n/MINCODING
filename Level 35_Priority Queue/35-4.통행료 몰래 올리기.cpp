#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct NODE {
    char from;
    char to;
    int cost;
};

struct order {
    bool operator()(NODE a, NODE b) {

        if (a.cost < b.cost)return false;
        if (a.cost > b.cost)return true;

        if (a.from < b.from)return false;
        if (a.from > b.from)return true;

        if (a.to < b.to)return false;
        if (a.to > b.to)return true;

        return false;
    }
};

priority_queue<NODE, vector<NODE>, order> q;
int n;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;
    //����⿡ ���� ������ �����ϰ� q�� push�ϱ� ����
    int k = 0;
    for (int from = 0; from < n; from++) {
        for (int to = 0; to < n; to++) {
            int cost;
            cin >> cost;
            if(cost > 0&& to >= k)
                q.push({ char(from + 'A'), char(to + 'A'), cost });
        }
        k++;
    }

    /*
    k ���� �̷��� ���� for�� ��� ����
    ��� �Է� cost���� ���ؼ��� �迭�� ������ �ξ�� �Ѵ�

    for (int y = 0; y < n; y++) {
		for (int x = y + 1; x < n; x++) {
			if (map[y][x] != 0) {
				char ch1 = 'A' + y;
				char ch2 = 'A' + x;
				q.push({ ch1, ch2, map[y][x] });
			}
		}
	}
    */


    NODE now;
    for (int i = 0; i < 10; i++) {

        now = q.top();
        q.pop();

        now.cost = now.cost * 2;
        q.push(now);
    }

    cout << now.cost << "����";

    return 0;
}