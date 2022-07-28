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

	char names[5][10] = { "Amy","Bob","Chloe","Diane","Edger" };
	int loveline[5][5] = {
		0,1,0,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0,
		1,0,0,0,0
	};
	int max_idx = 0, count[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (loveline[i][j])
				count[i]++;
		}
		if (count[max_idx] < count[i])
			max_idx = i;
	}
	cout << names[max_idx];
    return 0;
}