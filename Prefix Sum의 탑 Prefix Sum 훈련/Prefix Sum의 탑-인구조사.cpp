#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main() {
	
	// ������ �α� ���� ���� ��ȣ ������� �Էµ��� �����Ƿ�
	// ��� �Էµ� ������ prefix���

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