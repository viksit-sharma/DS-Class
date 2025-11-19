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
int postfixEval(string str)
{
    int res;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] <= 57 && str[i] >= 49)
        {
            int a = str[i] - '0';
            push(a);
            // cout << a << endl;
        }
        else if (str[i] == '+' || str[i] == '/' || str[i] == '*' || str[i] == '^' || str[i] == '-')
        {
            int op1 = pop();
            int op2 = pop();
            char opr = str[i];

            if (opr == '+')
            {
                res = op2 + op1;
            }
            else if (opr == '-')
            {
                res = op2 - op1;
            }
            else if (opr == '*')
            {
                res = op2 * op1;
            }
            else if (opr == '/')
            {
                res = op2 / op1;
            }
            else if (opr == '^')
            {
                res = op2 ^ op1;
            }
            // cout << res <<" ";
            push(res);
        }
    }
    return res;
}
int main()
{
    cout<<postfixEval("53*7-92*+");
}