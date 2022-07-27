#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    char input[10];
    int n, x=5,y=5;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (strcmp(input, "up") == 0)
            y -= 1;
        else if (strcmp(input, "down") == 0)
            y += 1;
        else if (strcmp(input, "left") == 0)
            x -= 1;
        else if (strcmp(input, "right") == 0)
            x += 1;
        else if (strcmp(input, "click") == 0)
            cout << y << "," << x<<endl;
    }
    return 0;
}