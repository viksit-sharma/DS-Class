#include <iostream>
#include <cstdlib>
#define max 10
using namespace std;
struct stack
{
    int data[max];
    int top;
};
stack s, *p;
void init()
{
    p = &s;
    p->top = -1;
}
int empty()
{
    if (p->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int full()
{
    if (p->top == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int x)
{
    if (full())
    {
        return;
    }
    p->top++;
    p->data[p->top] = x;
    cout << "\033[1;32m→ Pushed " << x << " onto stack.\033[0m\n";
}
int pop()
{
    int x;
    if (empty())
    {
        return -1;
    }
    x = p->data[p->top];
    p->top--;
    cout << "\033[1;31m→ Popped top element.\033[0m\n";
    return x;
}
void display()
{
    cout << "\033[1;36m→ Displaying stack elements...\033[0m\n";
    for (int i = 0; i < p->top + 1; i++)
    {
        cout << p->data[i] << " ";
    }
    cout << endl;
}
int main()
{
    init();
    int flag = 1;

    while (flag == 1)
    {
        // Clear screen each time
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        // Menu header with colors
        cout << "\033[1;34m"; // Bright blue
        cout << "+==========================================+\n";
        cout << "|               STACK MENU                 |\n";
        cout << "+==========================================+\n";
        cout << "\033[0m"; // Reset color

        // Menu options with color
        cout << "\033[1;33m"; // Yellow
        cout << "  [1] Push an element\n";
        cout << "  [2] Pop the top element\n";
        cout << "  [3] Display the stack\n";
        cout << "  [4] Exit program\n";
        cout << "\033[0m"; // Reset

        cout << "\033[1;34m+==========================================+\033[0m\n";

        cout << "\n\033[1;37mEnter your choice -> \033[0m";
        int n;
        cin >> n;
        cout << endl;

        if (n == 1)
        {
            int l;
            cout << "\033[1;36mEnter element to push: \033[0m";
            cin >> l;
            cout << endl;
            push(l);
        }
        else if (n == 2)
        {
            pop();
        }
        else if (n == 3)
        {
            display();
        }
        else if (n == 4)
        {
            cout << "\033[1;35mExiting... Have a great day!\033[0m\n";
            flag = 0;
        }
        else
        {
            cout << "\033[1;31mInvalid choice! Please try again.\033[0m\n";
        }

        if (flag != 0)
        {
            cout << "\n\033[1;30mPress Enter to continue...\033[0m";
            cin.ignore();
            cin.get();
        }
    }

    // cout << pop() << " " << pop() << " " << pop() << " " << pop() << " " << pop() << endl;
}