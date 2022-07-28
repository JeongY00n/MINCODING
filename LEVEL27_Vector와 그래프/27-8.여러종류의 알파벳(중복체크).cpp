#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;



string a;
int cnt[91] = { 0 }, sum = 0;
void find() {
    for (int i = 0; i < a.length(); i++) {
        if (cnt[a[i]] == 1)
            continue;
        cnt[a[i]] = 1;
        sum += cnt[a[i]];
    }
    cout << sum << "Á¾·ù";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    
    
    cin >> a;
    find();
    

    return 0;
}