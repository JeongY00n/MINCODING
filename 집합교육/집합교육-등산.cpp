#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;



int main() {
	int n, idx = 0;
	
	cin >> n;
	int first = 0, max=0;
	
	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;
		if (i != 1) {
			int interval = height - first;
			if (max < interval)
			{
				max = interval;
				idx = i;
			}
		}
		first = height;
	}
	if (max == 0)
		cout << 0;
	else	
		cout << idx - 1 << " " << idx;

	return 0;
}


