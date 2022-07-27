#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 


using namespace std;

string str;
string check[5] = {
    "KFC","MC","BICMAC","SHACK","SONY"
};
string change[5] = {
    "#BBQ#","#BBQ#","#MACBOOK#","#SHOCK#","#NONY#"
};
void find(int i) {
    str.replace(str.find(check[i]), check[i].length(), change[i]);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    cin >> str;


    for (int i = 0; i < 5; i++) {
        if (str.find(check[i]) == string::npos)
            ;
        else 
            find(i);
        
        
    }cout << str;
    return 0;
}