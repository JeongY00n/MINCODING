#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
vector<string> books;
bool bs(string book, int time) {
    int left = 0, right = N-1;
    int cnt = 0;
    while (left <= right) {
        //ã�� Ƚ���� ���� �߰��� �� ������ ã���־���Ѵ�.
        cnt++;
        if (time < cnt)
            return false;
        int mid = (left + right) / 2;
        if (books[mid] < book) {
            left = mid + 1;
        }
        else if (books[mid] > book) {
            right = mid - 1;
        }
        else {
            return true;
        }
        
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //binary search
    //���� �ʼ�!

    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        books.push_back(str);
    }
    sort(books.begin(), books.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        string book;
        int time;
        cin >> book >> time;

        if (bs(book, time)) cout << "pass\n";
        else cout << "fail\n";
    }

    return 0;
}


