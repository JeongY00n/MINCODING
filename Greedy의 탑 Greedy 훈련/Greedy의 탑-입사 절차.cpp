#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



// �� ����(co)�� ���� ������ �ϰ� �� ����(co) 1���� �ٸ� ����(in)�� ������ ����
// ����(in)�� ������ ���� �ٸ� �л���� ���ϸ鼭 ���� ��(in) ���� ū ���� ����
// ����(in)���� ���� ��� �� ��(in)���� �������ش�

struct STUDENT {
	int co;
	int in;
};
bool order(STUDENT a, STUDENT b) {

	if (a.co > b.co)return false;
	if (a.co < b.co)return true;

	return false;
}
int main() {

	int n;
	vector<STUDENT> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int co, in;
		cin >> co >> in;
		v.push_back({ co,in });
	}
	sort(v.begin(), v.end(), order);
	int cnt = n;
	int front = v.front().in;
	for (int i = 1; i < n; i++) {
		if (front > v[i].in)
			front = v[i].in;
		else
		{
			cnt--;
		}
	}

	cout << cnt;
	return 0;

}