#include<iostream>
#include<cstring>

using namespace std;


struct MC {
    char burger1[8];
    char burger2[8];
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    MC bob, tom;

    cin >> bob.burger1;
    cout << "bob.burger1=" << strlen(bob.burger1) << endl;

    cin >> bob.burger2;
    cout << "bob.burger2=" << strlen(bob.burger2) << endl;

    cin >> tom.burger1;
    cout << "tom.burger1=" << strlen(tom.burger1) << endl;

    cin >> tom.burger2;
    cout << "tom.burger2=" << strlen(tom.burger2);


    return 0;
}