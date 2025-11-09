#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *first, *temp, *ttemp, *p, *q, *t;
void init()
{
    first = ttemp = temp = p = NULL;
}
void createFirstNode(int f) // 1//
{
    first = new node;
    first->data = f;
    first->next = NULL;
}
void addAfter(int x, int y) // 2//
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
    temp->next = p;
}
// void addBefore(int x, int y) {
//     temp = first;
//     while(temp->data!=x) {
//         ttemp = temp;
//         temp = temp->next;
//     }
//     // ttemp = temp->next;
//     p = new node;
//     p->data = y;
//     p->next = ttemp;//making infinite loop because we linked p to previous one means p ke next mein previous ka address dal diya tha balki temp means next wale ka dalna tha
//     ttemp->next = p;
// }
void addBefore(int x, int y) // 3//
{
    temp = first;

    while (temp->data != x)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = new node;
    p->data = y;
    p->next = temp;
    ttemp->next = p;
}
void addBeforeMine(int x, int y) // 4//
{
    temp = first;
    while (temp->next->data != x)
    {
        temp = temp->next;
    }
    ttemp = new node;
    ttemp->data = y;
    ttemp->next = temp->next;
    temp->next = ttemp;
}
void swapFirstSecond()
{
    temp = first;
    ttemp = temp->next;
    temp->next = ttemp->next;
    ttemp->next = temp;
    first = ttemp;
}
void swapLastAndSecondLast() // 5
{
    temp = first;
    while (temp->next->next != NULL)
    {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = temp->next;
    temp->next->next = temp;
    temp->next = NULL;
    // temp->next->next = temp->next; // NULL->900
    // t = temp->next->next;                // 1000
    // temp->next->next = NULL;             // 1000->NULL
    // temp->next = t;                      // 900->1000
}
void swapMthAndNth(int m, int n) // 6
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
void swapFirstLast() // 7
{
    temp = ttemp = first;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    first = temp->next;
    temp->next->next = ttemp->next;
    temp->next = ttemp;
    ttemp->next = NULL;
}
void delFirst()
{
    temp = first;
    first = first->next;
    temp->next = NULL;
    delete temp;
}
void delLast()
{
    temp = first;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = NULL;
    delete ttemp;
}
void reverseLl() // 8
{
    swapFirstLast();
    temp = first;
    int m = 2, n = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        n++;
    }
    while (m <= n)
    {
        swapMthAndNth(m, n);
        m++;
        n--;
    }
}
void reverseLL()
{
    ttemp = first; // 100
    while (ttemp != NULL)
    {
        temp = ttemp->next; // 200//300//400//500//NULL
        ttemp->next = p;    // NULL//100//200//300//400
        p = ttemp;          // 100//200//300//400//500
        ttemp = temp;       // 200//300//400//500//NULL
    }
    first = p; // 500
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
void deleteNth(int n) // 9
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
void addAfterMine(int x, int y) // 10
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    ttemp = new node;
    ttemp->data = y;
    ttemp->next = temp->next;
    temp->next = ttemp;
}
void addNodeAfterLast(int y) // 11
{
    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = new node;
    ttemp->data = y;
    ttemp->next = NULL;
    temp->next = ttemp;
}
void addNodeAfterfirst(int y) // 12
{
    temp = first;
    ttemp = new node;
    ttemp->data = y;
    ttemp->next = temp->next;
    temp->next = ttemp;
}
void addNodeBeforeLast(int y) // 13
{
    temp = first;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = new node;
    ttemp->data = y;
    ttemp->next = temp->next;
    temp->next = ttemp;
}
void addNodeBeforeFirst(int x, int y) // 14
{
    temp = new node;
    temp->data = y;
    temp->next = first;
    first = temp;
}
void addNode(int x) // 15
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
void noToLinklist(int num)
{
    int tNum = num;
    int rev = 0;
    while (num > 0)
    {
        int lastDig = num % 10;
        rev = rev * 10 + lastDig;
        num = num / 10;
    }
    int f = rev % 10;
    rev = rev / 10; // 8764
    createFirstNode(f);
    for (int i = 0; rev > 0; i++)
    {
        int h = rev % 10;
        addNode(h);
        rev /= 10;
    }
}
void display() // 16
{
    temp = first;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    init();
    // createFirstNode(1);
    int flag = 1;
    char ans;
    int x, y;
    // addNode(2);
    // addNode(3);
    // addNode(4);
    // addNode(5);
    // addNode(6);
    // addNode(7);
    // addNode(8);
    // addNode(9);
    // addNode(10);
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // addNode();
    // while (flag == 1)
    // {
    //     cout << "Do you want to continue? \nEnter y to say yes\nEnter a to add node after an element\nEnter b to add node before an element\nEnter d to delete nth node ";
    //     cin >> ans;
    //     if (ans == 'y')
    //     {
    //         addNode();
    //     }
    //     else if (ans == 'd')
    //     {
    //         int n;
    //         cout << "Enter node to delete : ";
    //         cin >> n;
    //         deleteNth(n);
    //     }
    //     else if (ans == 's')
    //     {
    //         int n, m;
    //         cout << "Enter Mth node : ";
    //         cin >> m;
    //         cout << "Enter Nth node : ";
    //         cin >> n;
    //         swapMthAndNth(m, n);
    //     }
    //     else if (ans == 'l')
    //     {
    //         swapLastAndSecondLast();
    //     }
    // else if(ans=='a'){
    //     cout << "Give the node after which you want to add a node : ";
    //     cin >> x;
    //     cout << "Enter node to add after the given node  : ";
    //     cin >> y;

    //     addAfter(x, y);
    // }
    // else if(ans=='b'){
    //     cout << "Give the node before which you want to add a node : ";
    //     cin >> x;
    //     cout << "Enter node to add before the given node  : ";
    //     cin >> y;

    //     addBefore (x, y);
    // }
    // else if(ans=='f'){
    //     cout << "Give the node before which you want to add a node : ";
    //     cin >> x;
    //     cout << "Enter node to add before the given node  : ";
    //     cin >> y;

    //     addNodeBeforeFirst (x, y);
    // }
    // else if(ans=='l'){
    //     cout << "Give the node before which you want to add a node : ";
    //     cin >> x;
    //     cout << "Enter node to add before the given node  : ";
    //     cin >> y;

    //     addNodeBeforeLast (y);
    // }
    // else
    // {
    //     flag = 0;
    // swapFirstLast();
    // reverseLl();
    // delLast();
    // swapFirstSecond();
    // swapLastAndSecondLast();
    // reverseLL();
    // checkPlindrome();
    noToLinklist(123456);
    display();
    //     break;
    // }
}