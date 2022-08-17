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
	// 매번 add값을 push해주기 때문에 pq가 empty가 될 수가 없다!!
	// pq가 한개 남은 경우는 더이상 다른 값과 합할 수 없으므로
	// 종료 조건을 pq.size() != 1 으로 둔다!!
	while(pq.size()!=1) {
		int add = pq.top(); pq.pop();
		add += pq.top(); pq.pop();
		pq.push(add);
		time += add;
	}
	cout << time;
	return 0;

}