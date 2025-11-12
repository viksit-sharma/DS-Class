#include <iostream>
#include <cstdlib>
using namespace std;
struct stack
{
    int data;
    stack *next;
};
stack *top, *temp;
void init()
{
    top = temp = NULL;
}
void push(int x)
{
    temp = new stack;

    if (temp == NULL)
    {
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
}
int pop()
{
    int x;
    if (top == NULL)
    {
        return 0;
    }
    x = top->data;
    temp = top;
    top = top->next;
    temp->next = NULL;
    delete temp;
    return x;
}
void display() // 16
{
    temp = top;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    init();
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
}