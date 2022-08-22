#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;


//int n;
//int map[151] = { 0 };
//int dp[151];
//int maxScore = -2134567890;
//int dfs(int x) {
//	
//	if (x > n)
//		return 0;
//	if (x == n)
//	{
//		dp[n] = map[n];
//		return map[n];
//	}
//
//	if (dp[x] != -2134567890) return dp[x];
//
//	int jump2 = dfs(x + 2);
//	int jump7 = dfs(x + 7);
//
//	maxScore = max(jump2, jump7);
//
//	dp[x] = maxScore + map[x];
//
//	return dp[x];
//
//
//}
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> map[i];
//		dp[i] = -2134567890;
//	}
//
//
//	cout << dfs(0);
//
//
//}


struct Node {
	int row;
	int col;
};

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int n, map[20][20] = { 0 };
		cin >> n;
		Node node;
		vector<Node> home;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2)
				{		
					node.row = i;
					node.col = j;
				}
				if (map[i][j] == 1)
				{
					home.push_back({ i,j });
				}
			}
		}

		Node max;
		int max_dist = 0;
		for (int i = 0; i < home.size(); i++) {
			int dist = (home[i].row - node.row) * (home[i].row - node.row) + (home[i].col - node.col) * (home[i].col - node.col);
			if (max_dist < dist)
				max_dist = dist;
		}
		int ans = 2 * n;
		while (1) {
			if (max_dist < ans*ans)
			{
				ans -= 1;
			}
			else if (max_dist == ans * ans) {
				cout << "#" << test_case << " " << ans << endl;
				break;
			}
			else
			{
				cout << "#" << test_case << " " << ans + 1 << endl;
				break;
			}
		}

	}
	return 0;
}

