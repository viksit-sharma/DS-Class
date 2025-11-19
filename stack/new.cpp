#include <iostream>
#define max 5
using namespace std;
struct stack
{
    int data[max];
    int topAbove, topBelow;
};
stack s, *p, *q;
void init()
{
    p = &s;
    q = &s;
    p->topAbove = -1;
    q->topBelow = max;
}
int emptyAbove()
{
    if (p->topAbove == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int fullAbove()
{
    if (q->topBelow == p->topAbove - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void pushAbove(int x)
{
    if (fullAbove())
    {
        return;
    }
    p->topAbove++;
    p->data[p->topAbove] = x;
    cout << "\033[1;32m→ Pushed " << x << " onto stack.\033[0m\n";
}
int popAbove()
{
    int x;
    if (emptyAbove())
    {
        return -1;
    }
    x = p->data[p->topAbove];
    p->topAbove--;
    cout << "\033[1;31m→ Popped top element.\033[0m\n";
    return x;
}
int emptyBelow()
{
    if (q->topBelow == max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int fullBelow()
{
    if (q->topBelow == p->topAbove - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void pushBelow(int x)
{
    if (fullBelow())
    {
        return;
    }
    q->topBelow--;
    q->data[q->topBelow] = x;
    cout << "\033[1;32m→ Pushed " << x << " onto stack.\033[0m\n";
}
int popBelow()
{
    int x;
    if (emptyBelow())
    {
        return -1;
    }
    x = q->data[q->topBelow];
    q->topBelow++;
    cout << "\033[1;31m→ Popped top element.\033[0m\n";
    return x;
}
void display()
{
    cout << "\033[1;36m→ Displaying stack elements...\033[0m\n";
    for (int i = 0; i < max; i++)
    {
        cout << p->data[i] << " ";
    }
    cout << endl;
}

int main()
{
    init();
    pushAbove(1);
    pushAbove(2);
    pushAbove(3);
    pushBelow(4);
    pushBelow(5);
    cout << popBelow() << " " << popBelow() << endl;
    cout << popAbove() << " " << popAbove() << " " << popAbove();
}