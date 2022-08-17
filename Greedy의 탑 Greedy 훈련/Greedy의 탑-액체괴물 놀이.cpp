#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main() {

	int n;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int kg;
		cin >> kg;
		pq.push(kg);
	}

	int time = 0;
	// �Ź� add���� push���ֱ� ������ pq�� empty�� �� ���� ����!!
	// pq�� �Ѱ� ���� ���� ���̻� �ٸ� ���� ���� �� �����Ƿ�
	// ���� ������ pq.size() != 1 ���� �д�!!
	while(pq.size()!=1) {
		int add = pq.top(); pq.pop();
		add += pq.top(); pq.pop();
		pq.push(add);
		time += add;
	}
	cout << time;
	return 0;

}