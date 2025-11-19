#include <iostream>
#include <stdio.h>
using namespace std;
struct SCLL
{
    int data;
    SCLL *next;
};

SCLL *first, *temp, *ttemp, *p, *q, *t;

void init()
{
    first = ttemp = temp = NULL;
}

void createFirstNode(int x) // 1
{
    first = new SCLL;
    first->data = x;
    first->next = first;
}
// void addAfter(int x, int y) {
//     temp = first;
//     while(temp->data!=x) {
//         temp = temp->next;
//     }
//     ttemp = temp->next;
//     p = new SCLL;
//     p->data = y;
//     p->next = ttemp;
//     temp->next = p;
// }
// void addBefore(int x, int y) {
//     temp = first;
//     while(temp->data!=x) {
//         ttemp = temp;
//         temp = temp->next;
//     }
//     // ttemp = temp->next;
//     p = new SCLL;
//     p->data = y;
//     p->next = ttemp;//making infinite loop because we linked p to previous one means p ke next mein previous ka address dal diya tha balki temp means next wale ka dalna tha
//     ttemp->next = p;
// }

// void addBefore(int x, int y) {
//     temp = first;

//     while (temp->data != x) {
//         ttemp = temp;
//         temp = temp->next;
//     }
//     p = new SCLL;
//     p->data = y;
//     p->next = temp;
//     ttemp->next = p;
// }
void addBeforeMine(int x, int y) // 2
{
    temp = first;
    while (temp->next->data != x)
    {
        temp = temp->next;
    }
    ttemp = new SCLL;
    ttemp->data = y;
    ttemp->next = temp->next;
    temp->next = ttemp;
}

void swapMthAndNth(int m, int n) // 3
{
    temp = first;  // 100
    ttemp = first; // 100
    for (int i = 1; i < m; i++)
    {
        p = temp;          // 200
        temp = temp->next; // 300
    }
    for (int i = 1; i < n; i++)
    {
        q = ttemp;           // 600
        ttemp = ttemp->next; // 700
    }
    p->next = ttemp;          // 300->700
    q->next = temp;           // 700->300
    t = ttemp->next;          // 800
    ttemp->next = temp->next; // 800->400
    temp->next = t;           // 400->800
}
void deleteNth(int n) // 4
{
    temp = first;
    for (int i = 1; i < n; i++)
    {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = temp->next;
    temp->next = NULL;
    delete temp;
}
void addAfterMine(int x, int y) // 5
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    ttemp = new SCLL;
    ttemp->data = y;
    ttemp->next = temp->next;
    temp->next = ttemp;
}
void addNodeAfterLast(int y) // 6
{
    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = new SCLL;
    ttemp->data = y;
    ttemp->next = first;
    temp->next = ttemp;
}
void addNodeAfterfirst(int y) // 7
{
    temp = first;
    ttemp = new SCLL;
    ttemp->data = y;
    ttemp->next = temp->next;
    temp->next = ttemp;
}
void addNodeBeforeLast(int y) // 8
{
    temp = first;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = new SCLL;
    ttemp->data = y;
    ttemp->next = temp->next;
    temp->next = ttemp;
}

void addAfterLast(int x) // 9
{
    temp = first;
    while (temp->next->next != first)
    {
        temp = temp->next;
    }
}
void swapLastSeclast() // 10
{
    temp = first;
    while (temp->next->next != first)
    {
        ttemp = temp;
        temp = temp->next;
        t = temp->next;
    }
    p = temp->next;
    ttemp->next = temp->next;
    temp->next = first;
    t->next = temp;
    p = first;
}
void swapFirstSecond() // 11
{
    temp = first;      // 100
    temp = temp->next; // 200
    ttemp = first;     // 100
    while (ttemp->next != first)
    {
        ttemp = ttemp->next; // 300
    }
    first->next = temp->next; // 200->300
    temp->next = first;       // 300->100

    first = temp;        // 100->200
    ttemp->next = first; // 100->200
}
void addBeforeFirst(int x) // 12
{
    temp = first;
    ttemp = new SCLL;
    ttemp->data = x;
    ttemp->next = first;
    while (temp->next != first)
    {
        temp = temp->next;
    }
    temp->next = ttemp;
    first = ttemp;
}
void deleteFirst() // 13
{
    ttemp = temp = first;
    while (temp->next != first)
    {
        temp = temp->next;
    }
    first = temp->next = first->next;
    ttemp->next = NULL;
    delete ttemp;
}
void deleteLast() // 14
{
    temp = first;
    while (temp->next->next != first)
    {
        temp = temp->next;
        ttemp = temp->next;
    }
    temp->next = first;
    ttemp->next = NULL;
    delete ttemp;
}
void addNode(int x) // 15
{
    temp = first;
    while (temp->next != first)
    {
        temp = temp->next;
    }
    ttemp = new SCLL;
    ttemp->next = first;
    ttemp->data = x;
    temp->next = ttemp;
}
void display() // 16
{
    temp = first;
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != first);
}
int main()
{
    init();
    createFirstNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);
    addNode(7);
    addNode(8);
    addNode(9);
    addBeforeFirst(0);
    deleteFirst();
    deleteLast();
    swapFirstSecond();
    swapLastSeclast();
    display();
}