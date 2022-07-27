#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include<algorithm> 


using namespace std;

string str;
int ok=0;
int b = 0;
void find(int a) {
    a = str.find('[', a);
    if (a == -1) return;
    b = str.find(']', a + 1);

    int size = b - a;
    /*cout << size << endl;
    cout << str[a];*/
    if (size == 6) {
        for (int i = a + 1; i < b; i++) {
            if ('0' <= str[i] && str[i] <= '9')
            {
                ok = 1;
            }
            else
            {
                ok = 0;
                break;
            }
        }
        if (ok) {
            for (int i = a; i <= b; i++)
                cout << str[i];
        }cout << endl;
    }
    a = b + 1;
    find(a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;
    
    string code;
    for (int i = 0; i < n; i++) {
        cin >> str;
        find(0);
    }
    
    return 0;
}