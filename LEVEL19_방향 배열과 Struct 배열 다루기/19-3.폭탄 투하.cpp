#include<iostream>
using namespace std;



char map[4][5] = { '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_', };

void explode(int y, int x) {
	int check[8][2] = { -1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1 };
	for (int i = 0; i < 8; i++) {
		if (y + check[i][0] < 4 && y + check[i][0] >= 0 && x + check[i][1] < 5 && x + check[i][1] >= 0)		
			map[y + check[i][0]][x + check[i][1]] = '#';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	////////////////////////////////////////////////////

	int y, x;
	for (int i = 0; i < 2; i++)
	{
		cin >> y >> x;
		explode(y, x);
	}

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 5; col++) {
			cout << map[row][col] << " ";
		}cout << endl;
	}


	return 0;
}


