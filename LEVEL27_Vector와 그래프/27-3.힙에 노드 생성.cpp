#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;


struct NODE {
    int num;
    NODE* next;
};
NODE* head;
NODE* last;

void addNODE(int num) {
    if (head == NULL)
    {
        head = new NODE();
        head->num = num;
        last = head;
    }
    else {
        last->next = new NODE();
        last = last->next;
        last->num = num;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int input;
    cin >> input;

    for (int i = 1; i <= 4; i++) {
        addNODE(i * input);
    }

    NODE* p = head;
    while (p != NULL) {
        cout << p->num << " ";
        p = p->next;
    }
    

    return 0;
}