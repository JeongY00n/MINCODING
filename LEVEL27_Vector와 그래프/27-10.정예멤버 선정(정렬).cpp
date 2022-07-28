#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;



//트리 Tree-> 임의 점 두개를 연결하는 가장 짧은 경로가 유일하다
//NODE = n개, EDGE = n-1개
//첫 NODE를 제외한 나머지 NODE들은 EDGE를 가지고 있으므로
//EDGE의 개수는 n-1개가 된다


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    
    vector<int> A = { 2,6,3,7,1,1,3,4,2 };
    vector<int> B = { 6,4,2,4,1,1,5,8 };
    vector<int> C = { 9,2,3,4,2,1 };
    int map[3][3];
    int max = 0, min = 1000;

    for (int a = 0; a < 9; a++) {
        for (int b = a; b < 9; b++) {
            if (A[a] > A[b]) {
                int num = A[a];
                A[a] = A[b];
                A[b] = num;
            }
        }
    }
    map[0][0] = A[A.size() - 1];
    map[0][1] = A[A.size() - 2];
    map[0][2] = A[A.size() - 3];
    for (int a = 0; a < 8; a++) {
        for (int b = a; b < 8; b++) {
            if (B[a] > B[b]) {
                int num = B[a];
                B[a] = B[b];
                B[b] = num;
            }
        }
    }
    map[1][0] = B[0];
    map[1][1] = B[1];
    map[1][2] = B[2];
    for (int a = 0; a < 6; a++) {
        for (int b = a; b < 6; b++) {
            if (C[a] > C[b]) {
                int num = C[a];
                C[a] = C[b];
                C[b] = num;
            }
        }
    }
    map[2][0] = C[0];
    map[2][1] = C[1];
    map[2][2] = C[C.size() - 1];
       
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            cout << map[a][b] << " ";
        }cout << endl;
    }

    return 0;
}