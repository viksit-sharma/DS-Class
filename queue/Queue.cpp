#include <iostream>
using namespace std;
#define max 5
struct Queue
{
    int data[max];
    int front, rear;
};
Queue *p, q;
void init()
{
    p = &q;
    p->front = p->rear = -1;
}
int full()
{
    if (p->rear == max - 1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int empty()
{
    if (p->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enQ(int x)
{
    if (full() == -1)
    {
        return;
    }
    if (p->rear == -1)
    {
        p->front = p->rear = 0;
    }
    else
    {
        p->rear++;
    }
    p->data[p->rear] = x;
}
int main()
{
}