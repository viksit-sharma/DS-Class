#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next, *prev;
};
node *temp, *ttemp, *first, *p;

void createFirst() // 1
{

    first = new node;
    cin >> first->data;
    first->next = NULL;
    first->prev = NULL;
}
void ChexkPlaindrome()
{
    ttemp = temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != ttemp)
    {
        if (temp->data != ttemp->data)
        {
            cout << "Is not plaindrome" << endl;
            return;
        }
        temp = temp->prev;
        ttemp = ttemp->next;
    }
    cout << "Is palindrome" << endl;
}
void addNode() // 2
{
    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = new node;
    cin >> ttemp->data;
    ttemp->prev = temp;
    ttemp->next = NULL;
    temp->next = ttemp;
}
void addBefore(int x, int y) // 3
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    p = temp->prev;
    ttemp = new node;
    ttemp->data = y;
    ttemp->next = temp;
    ttemp->prev = p;
    p->next = ttemp;
    temp->prev = ttemp;
}
void addAfter(int x, int y) // 4
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    ttemp = temp->next;
    p = new node;
    p->data = y;
    p->next = ttemp;
    p->prev = temp;
    temp->next = p;
    ttemp->prev = p;
}
void delBefore(int x) // 5
{
    temp = first;
    while (temp->next->data != x)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = temp->prev = NULL;
    delete temp;
}
void deleteNth(int x) // 6
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->next = temp->prev = NULL;
    delete temp;
}
void swapLastSecondlast() // 7
{
    temp = first;
    while (temp->next->next != NULL)
    {
        temp = temp->next; // 500
    }
    temp->prev->next = temp->next; // 500->600
    temp->next->prev = temp->prev; // 500->400
    temp->prev = temp->next;       // 400->600
    temp->next->next = temp;
    temp->next = NULL;
}
void swapFirstSecond() // 8
{
    temp = first;
    temp = temp->next;
    first->next = temp->next;
    first->prev = temp;
    temp->prev = NULL;
    temp->next = first;
    first = temp;
}
void delAfter(int x) // 9
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = ttemp->next;
    ttemp->next->prev = temp;
    ttemp->next = NULL;
    ttemp->prev = NULL;
    delete ttemp;
}
void addNodeBeforeFirst() // 10
{
    temp = first;
    ttemp = new node;
    ttemp->next = first;
    ttemp->prev = NULL;
    temp->prev = ttemp;
    first = ttemp;
}
void swapMthAndNth(int m, int n) // 11
{
    temp = first;
    ttemp = first;
    for (int i = 1; i < m; i++)
    {
        temp = temp->next;
    }
    for (int i = 1; i < n; i++)
    {
        ttemp = ttemp->next;
    }
    temp->prev->next = ttemp;
    ttemp->prev->next = temp;
    temp->next->prev = ttemp;
    ttemp->next->prev = temp;
    p = temp->prev;
    node *next = temp->next;
    temp->next = ttemp->next;
    temp->prev = ttemp->prev;
    ttemp->next = next;
    ttemp->prev = p;
}
void display() // 12
{
    temp = first;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    createFirst();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    // swapLastSecondlast();
    ChexkPlaindrome();
    display();
}