// #include <iostream>
// #include <cstdlib>
// #define max 10
// using namespace std;
// struct stack
// {
//     char stk[max];
//     int top;
// };
// stack s, *p;
// void init()
// {
//     p = &s;
//     p->top = -1;
// }
// int empty()
// {
//     if (p->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int full()
// {
//     if (p->top == max - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// void push(int x)
// {
//     if (full())
//     {
//         return;
//     }
//     p->top++;
//     p->stk[p->top] = x;
//     cout << "\033[1;32m→ Pushed " << x << " onto stack.\033[0m\n";
// }
// int pop()
// {
//     int x;
//     if (empty())
//     {
//         return -1;
//     }
//     x = p->stk[p->top];
//     p->top--;
//     cout << "\033[1;31m→ Popped top element.\033[0m\n";
//     return x;
// }
// void display()
// {
//     cout << "\033[1;36m→ Displaying stack elements...\033[0m\n";
//     for (int i = 0; i < p->top + 1; i++)
//     {
//         cout << p->stk[i] << " ";
//     }
//     cout << endl;
// }

// char simplify(string str)
// {

//     int ps[15];
//     int j = 0;
//     for (int i = 0; i < 15; i++)
//     {
//         if (str[i] == '(')
//         {
//             push(str[i]);
//         }
//         else if (str[i] >= 97 || str[i] <= 122)
//         {
//             ps[j] = str[i];
//             j++;
//         }
//         else if (stk[p->top] == '(')
//         {
//             push(str[i]);
//         }
//         else if (str[i] == '^')
//         {
//             if (stk[top] != '^')
//             {
//                 push(str[i]);
//             }
//             else
//             {
//                 while (stk[top] != '+' || '-' || '*' || '/' || '(')
//                 {
//                     char x = pop(stk[top]);
//                     ps[j] = x;
//                     j++;
//                 }
//             }
//         }

//         else if (str[i] == '*' || '/')
//         {
//             if (stk[top] == '+' || '-')
//             {
//                 push(str[i]);
//             }
//             else
//             {
//                 while (stk[top] != '+' || '-' || '(')
//                 {
//                     char x = pop(stk[top]);
//                     ps[j] = x;
//                     j++;
//                 }
//             }
//         }
//         else if (str[i] == '-' || '+')
//         {
//             while (stk[top] != '(')
//             {
//                 char x = pop(stk[top]);
//                 ps[j] = x;
//                 j++;
//             }
//         }
//         else if (str[i] = ')')
//         {
//             while (stk[top] != '(')
//             {
//                 char x = pop(stk[top]);
//                 ps[j] = x;
//                 j++;
//             }
//             char d = pop(stk[top]);
//         }
//     }

//     return 0;
// }
#include <iostream>
#include <cstdlib>
#include <string>
#define max 15
using namespace std;

struct stack
{
    char stk[max];
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
    return (p->top == -1);
}

int full()
{
    return (p->top == max - 1);
}

void push(int x)
{
    if (full())
        return;

    p->top++;
    p->stk[p->top] = x;
    cout << "\033[1;32m→ Pushed " << (char)x << " onto stack.\033[0m\n";
}

int pop()
{
    if (empty())
        return -1;

    int x = p->stk[p->top];
    p->top--;
    cout << "\033[1;31m→ Popped top element.\033[0m\n";
    return x;
}

void display()
{
    cout << "\033[1;36m→ Displaying stack elements...\033[0m\n";
    for (int i = 0; i <= p->top; i++)
    {
        cout << p->stk[i] << " ";
    }
    cout << endl;
}
char *simplify(string str)
{
    static char ps[30];
    int j = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            push(str[i]);

        else if (str[i] >= 'a' && str[i] <= 'z')
            ps[j++] = str[i];

        else if (!empty() && p->stk[p->top] == '(')
            push(str[i]);

        else if (str[i] == '^')
        {
            if (!empty() && p->stk[p->top] != '^')
                push(str[i]);
            else
                while (!empty() && p->stk[p->top] != '+' &&
                       p->stk[p->top] != '-' &&
                       p->stk[p->top] != '*' &&
                       p->stk[p->top] != '/' &&
                       p->stk[p->top] != '(')
                    ps[j++] = pop();
        }

        else if (str[i] == '*' || str[i] == '/')
        {
            if (!empty() && (p->stk[p->top] == '+' || p->stk[p->top] == '-'))
                push(str[i]);
            else
                while (!empty() && p->stk[p->top] != '+' &&
                       p->stk[p->top] != '-' &&
                       p->stk[p->top] != '(')
                    ps[j++] = pop();
        }

        else if (str[i] == '-' || str[i] == '+')
        {
            while (!empty() && p->stk[p->top] != '(')
            ps[j++] = pop();
            push(str[i]);
        }

        else if (str[i] == ')')
        {
            while (!empty() && p->stk[p->top] != '(')
                if (p->stk[p->top] != '(' || p->stk[p->top] != ')')
                    ps[j++] = pop();
                else
                    char l = pop();
            if (!empty())
                pop();
        }
    }

    while (!empty())
        ps[j++] = pop();

    ps[j] = '\0';
    return ps;
}

// char *simplify(string str)
// {
//     static char ps[15];
//     int j = 0;

//     for (int i = 0; i < 15; i++)
//     {
//         if (str[i] == '(')
//         {
//             push(str[i]);
//         }
//         else if (str[i] >= 'a' && str[i] <= 'z')
//         {
//             ps[j++] = str[i];
//         }
//         else if (p->stk[p->top] == '(')
//         {
//             push(str[i]);
//         }
//         else if (str[i] == '^')
//         {
//             if (p->stk[p->top] != '^')
//             {
//                 push(str[i]);
//             }
//             else
//             {
//                 while (p->stk[p->top] != '+' &&
//                        p->stk[p->top] != '-' &&
//                        p->stk[p->top] != '*' &&
//                        p->stk[p->top] != '/' &&
//                        p->stk[p->top] != '(')
//                 {
//                     char x = pop();
//                     ps[j++] = x;
//                 }
//             }
//         }
//         else if (str[i] == '*' || str[i] == '/')
//         {
//             if (p->stk[p->top] == '+' || p->stk[p->top] == '-')
//             {
//                 push(str[i]);
//             }
//             else
//             {
//                 while (p->stk[p->top] != '+' &&
//                        p->stk[p->top] != '-' &&
//                        p->stk[p->top] != '(')
//                 {
//                     char x = pop();
//                     ps[j++] = x;
//                 }
//             }
//         }
//         else if (str[i] == '-' || str[i] == '+')
//         {
//             while (p->stk[p->top] != '(')
//             {
//                 char x = pop();
//                 ps[j++] = x;
//             }
//         }
//         else if (str[i] == ')')
//         {
//             while (p->stk[p->top] != '(')
//             {
//                 char x = pop();
//                 ps[j++] = x;
//             }
//             char d = pop();
//         }
//     }
//     ps[j] = '\0';
//     return ps;
// }
int main()
{

    init();
    string str = "(a+b^(c+d/e)-f)";

    cout << simplify(str);
}