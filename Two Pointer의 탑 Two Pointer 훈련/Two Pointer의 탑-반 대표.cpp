#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



struct Student {
	int stats;
	int classnum;
};

bool order(Student a, Student b) {
	//sort와 priority queue에서의 >,< 다름
	if (a.stats > b.stats)return false;
	if (a.stats < b.stats)return true;

	if (a.stats < b.stats)return false;
	if (a.classnum > b.classnum)return true;

	return false;
}

int n, m;
Student student[1000000];
int MIN = 2134567890;
void Find() {
	int left = 0, right = 0;
	int cnum[1000000] = { 0 };
	queue<Student> v;

	while (right < n * m) {
		int sum = 0;
		int cnt = 0;

		if (cnt<n) {
			v.push(student[right]);
			if (cnum[student[right].classnum] == 0)
				cnt++;
			cnum[student[right].classnum] += 1;
			right++;
		}
		else if(cnt>=n) {
			sum = v.back().stats - v.front().stats;
			if (sum < MIN)
				MIN = sum;
			cnum[v.front().classnum] -= 1;
			if (cnum[v.front().classnum] == 0)
				cnt--;
			v.pop();
			left++;
		}
	}

}

int main() {
	cin >> n >> m;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int stats;
			cin >> stats;
			student[k++] = { stats, i };
		}
		
	}
	sort(student, student + (n*m), order);

	Find();
	cout << MIN;
}