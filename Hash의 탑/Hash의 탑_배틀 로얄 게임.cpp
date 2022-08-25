#include <iostream>
#include<stdlib.h>
#include<unordered_map>
using namespace std;

struct info {
	int cnt;
	int score;
};

unordered_map<string, info>team;
void solution() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int score; string teamName;
		cin >> teamName >> score;
		team[teamName].score = team[teamName].score + score;
		team[teamName].cnt = team[teamName].cnt + 1;
	}
	string coco, cocoF;
	cin >> coco >> cocoF;
	cout << team[coco].cnt << " " << team[coco].score << endl;
	cout << team[cocoF].cnt << " " << team[cocoF].score << endl;
	if (team[coco].score < team[cocoF].score)
		cout << cocoF;
	else
		cout << coco;
}
int main() 
{
	solution();
	return 0;
}

