#include<iostream>
#include<cstring>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int st = 1;
    char push[5];
    for (int i = 0; i < 5; i++) {
        cin >> push;
        
        if (strcmp(push, "up") == 0) {
            if (st == 0)  //0ÃþÀº ¾øÀ½
                st = 1;
            
            st++;
        }
        else if (strcmp(push, "down") == 0) {
            if (st == 0)
                st = -1;
        
            st--;
        }
    }

    if (st < 0)
        cout << "B" << abs(st);
    else
        cout << st;
    return 0;
}