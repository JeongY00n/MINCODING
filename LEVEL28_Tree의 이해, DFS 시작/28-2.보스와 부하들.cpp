#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;



//Ʈ�� Tree-> ���� �� �ΰ��� �����ϴ� ���� ª�� ��ΰ� �����ϴ�
//NODE = n��, EDGE = n-1��
//ù NODE�� ������ ������ NODE���� EDGE�� ������ �����Ƿ�
//EDGE�� ������ n-1���� �ȴ�


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int num; cin >> num;
    int arr[10][10] = { 0 };
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "boss:";
    for (int i = 0; i < num; i++) {
        if (arr[i][0] == 1)
            cout << i << " ";
    }

    cout << "\nunder:";
    for (int i = 0; i < num; i++) {
        if (arr[0][i] == 1)
            cout << i << " ";
    }

    return 0;
}