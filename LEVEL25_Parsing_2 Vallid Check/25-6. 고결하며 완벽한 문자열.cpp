
//트리 Tree-> 임의 점 두개를 연결하는 가장 짧은 경로가 유일하다
//NODE = n개, EDGE = n-1개
//첫 NODE를 제외한 나머지 NODE들은 EDGE를 가지고 있으므로
//EDGE의 개수는 n-1개가 된다


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 

using namespace std;

string str;
int ok = 0;
int idx = 0;

void check_str() {
    int check[123] = { 0 };
    //i<=str.find('>')에서도 idx조건 추가해주기!!!!!
    for (int i = idx; i <= str.find('>', idx); i++) {
        ok = 0;

        if (check[str[i]] == 1)
        {
            cout << "X";
            ok = 1;
            idx = i;
            return;
        }

        if (str[i] == '>')
        {
            idx = i;
            return;
        }

        check[str[i]] = 1;

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        idx = 0;
        ok = 0;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (ok)
                break;

            if (str.find('<', idx) == string::npos)
                ;
            else
            {
                idx = str.find('<', idx)+1;
                check_str();
            }
        }

        if (!ok)
            cout << "O";
    }

    return 0;
}