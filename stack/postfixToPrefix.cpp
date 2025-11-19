#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct stack
{
    string data;
    stack *next;
};
stack *top, *temp;
void init()
{
    top = temp = NULL;
}
void push(string x)
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
string pop()
{
    string x;
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
string prefixToInfix(string str)
{
    string str1, str2, str3, str4, str5;
    // reverse(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] <= 90 && str[i] >= 65 || str[i] <= 122 && str[i] >= 97)
        {
            push(string(1, str[i]));
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^')
        {
            str1 = pop();
            str2 = pop();
            str3 = str[i];
            str4 = str3 + str2;
            str5 = str4 + str1;
            push(str5);
        }
    }
    return top->data;
}
int main()
{
    cout << prefixToInfix("abc+de-*+");
}