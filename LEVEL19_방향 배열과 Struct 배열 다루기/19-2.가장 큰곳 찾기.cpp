#include<iostream>
using namespace std;

int result = 0;
int MAP[5][5] = {
	{3, 3, 5, 3, 1},
	{2, 2, 4, 2, 6},
	{4, 9, 2, 3, 4},
	{1, 1, 1, 1, 1},
	{3, 3, 5, 9, 2}
};
void sum(int y, int x) {
	result = 0;
	int go[4][2] = { -1,-1,-1,1,1,-1,1,1 };
	for (int i = 0; i < 4; i++)
	{
		if (y + go[i][0] >= 5 || y + go[i][0] < 0 || x + go[i][1] >= 5 || x + go[i][1] < 0) continue;
		result += MAP[y + go[i][0]][x + go[i][1]];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	////////////////////////////////////////////////////


	int y, x;
	int max = 0;

	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			sum(row, col);
			if (max < result) {
				max = result;
				y = row; x = col;
			}
		}
	}
	cout << y << " " << x;
	return 0;
}