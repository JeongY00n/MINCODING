#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int fibo[40] = { 0 };
int getFibo(int n) {

	if (n == 1)return 0;
	if (n == 2)return 1;

	int a = getFibo(n - 1);
	int b = getFibo(n - 2);

	fibo[n] = a + b;
	return fibo[n];
}

int main() {

	int n;
	cin >> n;
	fibo[1] = 0;
	fibo[2] = 1;

	/*for (int i = 3; i <= n; i++) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
	cout << fibo[n];
	*/

	cout<<getFibo(n);


	return 0;

}