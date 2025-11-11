#include <iostream>
using namespace std;
struct node
{
    int coef, pow;
    node *next;
};
node *first, *temp, *ttemp, *p, *q;
void init()
{
    first = temp = ttemp = p = q = NULL;
}
void CreateFirst(int coef, int pow)
{
    first = new node;
    first->coef = coef;
    first->pow = pow;
    first->next = NULL;
}
void addNode(int coef, int pow)
{
    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = new node;
    ttemp->coef = coef;
    ttemp->pow = pow;
    ttemp->next = NULL;
    temp->next = ttemp;
}
void addBefFirst(int coef, int pow)
{
    temp = first;
    ttemp = new node;
    ttemp->coef = coef;
    ttemp->pow = pow;
    ttemp->next = temp;
    first = ttemp;
}
void addBefore(int n, int coef, int pow)
{
    temp = first;
    for (int i = 1; i < n; i++)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = new node;
    p->coef = coef;
    p->pow = pow;
    p->next = temp;
    ttemp->next = p;
}
// void checkIp(int coef, int pow)
// {
//     p = q = first;
//     int m = 0;
//     while (q->next != NULL)
//     {
//         q = q->next;
//         m++;
//     }
//     if (m <= 1)
//     {
//         if (first->pow < pow)
//         {
//             addBefFirst(coef, pow);
//             return;
//         }
//         else
//         {
//             addNode(coef, pow);
//             return;
//         }
//     }

//     temp = p->next;
//     ttemp = temp->next;

//     if (first->pow < pow)
//     {
//         addBefFirst(coef, pow);
//         return;
//     }
//     else if (pow < first->pow && pow > temp->pow)
//     {
//         addBefore(2, coef, pow);
//         return;
//     }
//     else if (temp->pow > pow && ttemp->pow < pow)
//     {
//         addBefore(3, coef, pow);
//         return;
//     }
//     else
//     {
//         temp = temp->next;
//         ttemp = ttemp->next;
//         if (temp->pow > pow && ttemp->pow < pow)
//         {
//             addBefore(4, coef, pow);
//             return;
//         }
//         else
//         {
//             addNode(coef, pow);
//         }
//     }
// }
void swapFirstSec()
{
    temp = first;
    ttemp = temp->next;
    p = ttemp->next;
    ttemp->next = temp;
    temp->next = p;
    first = ttemp;
}
void swapconse(int pow1, int pow2) // pow1<pow2
{
    temp = ttemp = first;
    while (temp->pow != pow1)
    {
        q = temp;
        temp = temp->next;
    }
    while (ttemp->pow != pow2)
    {
        ttemp = ttemp->next;
    }
    q->next = ttemp;
    p = ttemp->next;
    ttemp->next = temp;
    temp->next = p;
}
void swapLastSeclast()
{
    temp = first;
    while (temp->next->next != NULL)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = temp->next;
    ttemp->next = p;
    temp->next = NULL;
    p->next = temp;
}

// void sortLl()
// {
//     temp = first;
//     int len = 0;
//     while (temp != NULL)
//     {
//         temp = temp->next;
//         len++;
//     }
//     for (int i = 0; i < len; i++)
//     {
//         temp = first;
//         ttemp = temp->next;
//         for (int j = 0; j < len - i && ttemp != NULL; j++)
//         {
//             if (temp->pow < ttemp->pow && temp == first)
//             {
//                 swapFirstSec();
//             }
//             else if (temp->pow < ttemp->pow && ttemp->next == NULL)
//             {
//                 swapLastSeclast();
//             }
//             else if (temp->pow < ttemp->pow)
//             {
//                 swapconse(temp->pow, ttemp->pow);
//             }

//             temp = temp->next;
//             ttemp = ttemp->next;
//         }
//     }
// }

void sortLl()
{
    temp = first;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    for (int i = 0; i < len; i++)
    {
        node *prev = NULL;
        temp = first;

        while (temp != NULL && temp->next != NULL)
        {
            ttemp = temp->next;

            if (temp->pow < ttemp->pow)
            {
                if (temp == first)
                {
                    swapFirstSec();
                    prev = first;
                }
                else if (ttemp->next == NULL)
                {
                    swapLastSeclast();
                    break;
                }
                else
                {
                    swapconse(temp->pow, ttemp->pow);
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }
}

void display()
{
    temp = first;
    while (temp != NULL)
    {
        cout << "coef = " << temp->coef << " and pow = " << temp->pow << endl;
        temp = temp->next;
    }
}

int main()
{
    init();
    CreateFirst(4, 4);
    addNode(3, 2);
    addNode(5, 7);
    addNode(5, 0);
    addNode(2, 1);
    addNode(3, 3);
    addNode(1, 8);
    addNode(3, 5);
    addNode(3, 6);
    addNode(5, 9);
    addNode(5, 10);
    addNode(2, 11);
    // addNode(3, 0);
    // addNode(5, 0);
    // addNode(5, 0);
    // addNode(2, 0);
    // addNode(5, 0);
    // addNode(2, 0);
    // addNode(2, 0);
    sortLl();
    display();
}
