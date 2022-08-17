#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main() {
	
	// 마을의 인구 수가 마을 번호 순서대로 입력되지 않으므로
	// 모두 입력된 다음에 prefix계산

	int n, m;
	int village[100001] = { 0 };
	int prefix[100001] = { 0 };

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int vNum;
		cin >> vNum;
		cin >> village[vNum];
	}

	for (int i = 1; i <= m; i++) {
		prefix[i] = prefix[i - 1] + village[i];
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int A, B;
		cin >> A >> B;
		cout << prefix[B] - prefix[A] + village[A] << endl;
	}

	return 0;

}