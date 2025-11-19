#include <iostream>
#include <cstdlib>
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
        return "";
    }
    x = top->data;
    temp = top;
    top = top->next;
    temp->next = NULL;
    delete temp;
    return x;
}
string infixToPostfix(string str)
{
    string pushstring = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            push(string(1, str[i]));
            // cout << "1 pushed " << str[i]<<endl;
        }
        else if (str[i] <= 90 && str[i] >= 65 || str[i] <= 122 && str[i] >= 97)
        {
            pushstring += str[i];
            // cout << "2 pushedstring " << str[i]<<endl;
        }
        else if (str[i] == '^')
        {
            while (top->data != "+" && top->data != "-" && top->data != "*" && top->data != "/" && top->data != "(")
            {
                pushstring += pop();
                // cout << "3 popedstring " << pop()<<endl;
            }
            push(string(1, str[i]));
            // cout << "4 pushed " << str[i]<<endl;
        }
        else if (str[i] == '*' || str[i] == '/')
        {
            while (top->data != "+" && top->data != "-" && top->data != "(")
            {
                pushstring += pop();
                // cout << "5 popedstring " << pop()<<endl;
            }
            push(string(1, str[i]));
            // cout << "5 pushed " << str[i]<<endl;
        }
        else if (str[i] == '-' || str[i] == '+')
        {
            while (top->data != "(")
            {
                pushstring += pop();
                // cout << "6 pushedstring " << pop()<<endl;
            }
            push(string(1, str[i]));
            // cout << "7 pushed " << str[i]<<endl;
        }
        else if (str[i] == ')')
        {
            while (top->data != "(")
            {
                pushstring += pop();
                // cout << "8 popedstring " << pop()<<endl;
            }
            string x = pop();
        }
    }
    return pushstring;
}
int main(){
    init();
    cout << infixToPostfix("(a+b*(c^d-e)^(f+g*h)-i)");
}