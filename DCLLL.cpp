#include <iostream>
using namespace std;
struct DCLL
{
    int data;
    DCLL *next, *prev;
};
DCLL *first, *temp, *ttemp, *p, *last, *secondLast;
void createFirst(int x) // 1
{
    first = new DCLL;
    first->data = x;
    first->next = first;
    first->prev = first;
}
void addNode(int x) // 2
{
    ttemp = new DCLL;
    temp = first->prev;
    ttemp->prev = temp;
    ttemp->data = x;
    ttemp->next = first;
    temp->next = ttemp;
    first->prev = ttemp;
    
}
void addNodeBeforeFirst(int x) // 3
{
    ttemp = new DCLL;
    ttemp->data = x;
    ttemp->next = first;
    ttemp->prev = first->prev;
    first->prev->next = ttemp;
    first->prev = ttemp;
    first = ttemp;
}
void swapLastSecondlast() // 4
{
    temp = first;
    temp = temp->prev->prev;
    secondLast = temp;
    last = temp->next;
    secondLast->prev->next = last;
    last->prev = secondLast->prev;
    last->next = secondLast;
    secondLast->prev = last;
    secondLast->next = first;
    first->prev = secondLast;
}
void delFirst() // 5
{
    first->next->prev = first->prev; // first jis(second ka previous)
    first->prev->next = first->next;
    p = first->next;
    temp = first;
    temp->prev = temp->next = NULL;
    delete temp;
    first = p;
}
void delLast() // 6
{
    // temp = first->prev;
    // ttemp = first->prev;
    // p = ttemp->prev;
    // ttemp->prev->next = first;
    // ttemp = p;
    // ttemp->prev = temp->next = NULL;
    // delete temp;
    temp = first->prev;
    first->prev->prev->next = first;
    first->prev = temp->prev;
    temp->prev = temp->next = NULL;
    delete temp;
}
void swapFirstSecond() // 7
{
    temp = first;
    ttemp = first->prev;
    temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev->prev = temp;
    temp->prev = first->prev;
    temp->next = first;
    first = temp;
    ttemp->next = first;
}
void display() // 8
{
    temp = first;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != first);
}
int main()
{
    createFirst(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);
    addNode(7);
    addNode(8);
    addNode(9);
    addNode(10);
    // swapLastSecondlast();
    // swapFirstSecond();
    // addNodeBeforeFirst(0);
    // delFirst();
    delLast();
    display();
}