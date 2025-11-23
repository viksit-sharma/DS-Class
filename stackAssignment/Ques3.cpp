// Take two steps of same size and merge these two firstStks in the third step such that elements of both the firstStk appears in alternate order in the third firstStk
#include <iostream>
#include <math.h>
using namespace std;
struct firstStk
{
    char data;
    firstStk *next;
};
firstStk *topF, *tempF;
void initF()
{
    topF = tempF = NULL;
}
void pushF(char x)
{
    tempF = new firstStk;

    if (tempF == NULL)
    {
        return;
    }
    tempF->data = x;
    tempF->next = topF;
    topF = tempF;
}
char popF()
{
    char x;
    if (topF == NULL)
    {
        return 0;
    }
    x = topF->data;
    tempF = topF;
    topF = topF->next;
    tempF->next = NULL;
    delete tempF;
    return x;
}
struct secondStk
{
    char data;
    secondStk *next;
};
secondStk *topS, *tempS;
void initS()
{
    topS = tempS = NULL;
}
void pushS(char x)
{
    tempS = new secondStk;

    if (tempS == NULL)
    {
        return;
    }
    tempS->data = x;
    tempS->next = topS;
    topS = tempS;
}
char popS()
{
    char x;
    if (topS == NULL)
    {
        return 0;
    }
    x = topS->data;
    tempS = topS;
    topS = topS->next;
    tempS->next = NULL;
    delete tempS;
    return x;
}
struct thirdStk
{
    char data;
    thirdStk *next;
};
thirdStk *top, *temp;
void init()
{
    top = temp = NULL;
}
void push(char x)
{
    temp = new thirdStk;

    if (temp == NULL)
    {
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
}
char pop()
{
    char x;
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
void merge(int totalLen)
{
    int i = 1;
    while (i < totalLen + 1)
    {
        if (i % 2 == 0)
        {
            push(popS());
        }
        else
        {
            push(popF());
        }
        i++;
    }
}
void display()
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
    string num1;
    string num2;
    cout << "Enter string for first stack : ";
    cin >> num1;
    cout << endl
         << "Enter string for second stack : ";
    cin >> num2;
    int num1Len = num1.length();
    int num2Len = num2.length();
    for (int i = 0; i < num1Len; i++)
    {
        pushF(num1[i]);
    }
    for (int i = 0; i < num2Len; i++)
    {
        pushS(num2[i]);
    }
    int totalLen = num1Len + num2Len;
    merge(totalLen);
    for (int i = 0; i < num1Len + num2Len; i++)
    {
        cout << pop() << " ";
    }
}