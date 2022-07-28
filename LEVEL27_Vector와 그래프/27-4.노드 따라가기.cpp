#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //<- c char[]
#include<string> //<- c++ string
#include <vector>

using namespace std;

struct NODE {
    char ch;
    NODE* next;
};
NODE* head;
NODE* last;
void addNODE(char ch) {
    if (head == NULL) {
        head = new NODE();
        head->ch = ch;
        last = head;
    }
    else {
        last->next = new NODE();
        last = last->next;
        last->ch = ch;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int input; cin >> input;

    char ch = input - 11 + 'A';
    for (int i = 0; i < 4; i++) {
        addNODE(ch++);
    }
    NODE* p = head;
    while (p != NULL) {
        cout << p->ch;
        p = p->next;
    }
    return 0;
}