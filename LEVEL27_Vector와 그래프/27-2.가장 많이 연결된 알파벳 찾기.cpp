#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    int arr[4][4], sum[4] = { 0 }, max = 0;
    for (int from = 0; from < 4; from++) {
        for (int to = 0; to < 4; to++) {
            cin >> arr[from][to];
            if (arr[from][to] == 1)
                sum[from] += 1;
        }
        //max를 인덱스 값으로 두어서 sum배열에서 값 비교
        if (sum[max] < sum[from]) {
            max = from;
        }
    }
    char out = 'A' + max;
    cout << out;
    return 0;
}