#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
    char data;
    node *next;
};
node *first, *temp, *ttemp, *p, *q, *t;
void init()
{
    first = ttemp = temp = NULL;
}
void createFirstNode(char x)
{
    first = new node;
    first->data = x;
    first->next = NULL;
}
void checkPlindrome()
{
    temp = first;
    int n = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        n++;
    }
    int mid = n % 2 == 0 ? n / 2 + 1 : n / 2 + 2;
    n = 1;
    temp = first;
    while (mid > n)
    {
        temp = temp->next;
        n++;
    }

    q = first;
    p = NULL;
    while (temp != NULL)
    {
        ttemp = temp->next;
        temp->next = p;
        p = temp;
        temp = ttemp;
    }

    t = temp = p;
    while (t != NULL)
    {
        if (t->data != q->data)
        {
            cout << "Is not a Palindrome" << endl;
            p = NULL;
            while (temp != NULL)
            {
                ttemp = temp->next;
                temp->next = p;
                p = temp;
                temp = ttemp;
            }

            return;
        }
        t = t->next;
        q = q->next;
    }
    cout << "Is palindrome" << endl;
    p = NULL;
    while (temp != NULL)
    {
        ttemp = temp->next;
        temp->next = p;
        p = temp;
        temp = ttemp;
    }
}
void addNode(char x)
{
    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = new node;
    ttemp->next = NULL;
    ttemp->data = x;
    temp->next = ttemp;
}
void display()
{
    temp = first;
    cout << "The elements of link list are : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// int checkPal()
// {
//     temp = first;
//     char arr[9];
//     for (int i = 0; temp != NULL; i++)
//     {
//         arr[i] = temp->data;
//         temp = temp->next;
//     }
//     int i = 0;
//     while (i < 5)
//     {
//         if (arr[i] != arr[8 - i])
//         {
//             return -1;
//         }
//         i++;
//     }
//     return 1;
// }
int main()
{

    char str[] = "MalayalaM";

    createFirstNode(str[0]);

    for (int i = 1; i < 9; i++)
    {
        addNode(str[i]);
    }

    checkPlindrome();
    // int result = checkPal();

    // if (result == 1)
    // {
    //     cout << ("Is Palindrome !!!");
    // }
    // else
    // {
    //     cout << ("Is not plaindrome !!!");
    // }
}