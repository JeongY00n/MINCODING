#include<iostream>
#include<cstring>

using namespace std;


struct Train{
    int win;
    char name[8];
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    Train train[7] = {
    {15, "summer"},
    {33, "cloe"},
    {24, "summer"},
    {28, "niki"},
    {32, "jenny"},
    {20, "summer"},
    {40, "coco"}
    };

    char name[8];
    int age;
    cin >> name >> age;
    
    for (int i = 0; i < 7; i++) {
        if (strcmp(train[i].name, name)==0) {
            if (train[i].win == age) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}