#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;

vector<int> input(6);
string mx;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    
    int x;

    for (int i = 0; i < 6; i++)
        cin >> input[i];
    cin >> mx;
    
    for (int i = 0; i < 6; i++) {
        //min, max값 초기화 필요
        int min = 100, min_index = 0, max = 0, max_index = 0;
        
        if (mx[i] == 'm') {
            
            for (x = 0; x < input.size(); x++) {
                if (min > input[x]) {
                    min = input[x];
                    min_index = x;
                }
            }
            cout << min;
            
            
            //벡터의 특정 인덱스에 있는 원소를 삭제하고 싶은 경우
            //input.erase(input.begin() + i)
            
            input.erase(input.begin() + min_index);
        
        }
        if (mx[i] == 'x') {
            
            for (x = 0; x < input.size(); x++) {
                if (max < input[x]) {
                    max = input[x];
                    max_index = x;
                }
            }
            cout << max;
            input.erase(input.begin() + max_index);
        }
    }


    return 0;
}