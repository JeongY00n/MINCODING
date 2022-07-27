#include<iostream>
#include<cstring>

using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    char login[2][20] = { "qlqlaqkq","tkaruqtkf" };
    char id[20];
    char password[20];
    cin >> id >> password;
    if (strcmp(login[0], id) == 0 and strcmp(login[1], password) == 0)
        cout << "LOGIN";
    else
        cout << "INVALID";
    return 0;
}