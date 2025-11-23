// Take two steps of same size and merge these two firstStks in the third step such that elements of both the firstStk appears in alternate order in the third firstStk
#include <iostream>
#include <math.h>
using namespace std;
//FIRST STACK
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
//SECOND STACK
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
//THIRD STACK IN WHICH ELEMENTS FO FIRST AND SECOND STACKS WILL COME ALTERNATELY
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
void merge(int totalLen)//MERGE FUNCTION THAT WILL MERGE BOTH FIRST AND SECOND FUNCTION ALTERNATIVELY IN THIRD STACK
{
    int i = 1;//INITIALLISED I BY 1
    while (i < totalLen + 1)//LOOP RUNS UNTIL I IS NOT EQUAL TO  TOTAL LENGTH i.e. THE SUM OF LENGTH OF FIRST AND SECOND STACK AND PUSHES FROM SECOND IF VALUE OF I IS EVEN AND PUSHES FROM FIRST IF THE VALUE OF I IS ODD
    {
        if (i % 2 == 0)//IF I IS EVEN THEN THIS WILL RUN
        {
            push(popS());//PUSHING IN THIRD STACK BY POPPING FROM SECOND STACK
        }
        else//OTHERWISE THIS WILL RUN FOR ODD VALUE OF I
        {
            push(popF());//PUSHING IN THIRD STACK BY POPPING FROM FIRST STACK
        }
        i++;//INCREMENTING I BY 1 TO GO TO NEXT VALUE
    }
}
int main()
{
    string num1;//FIRST STRING
    string num2;//SECOND STRING
    cout << "Enter string for first stack : ";
    cin >> num1;//TAKING INPUT FOR FIRST STRING
    cout << endl
         << "Enter string for second stack : ";
    cin >> num2;//TAKING INPUT FOR SECOND STRING
    int num1Len = num1.length();//FINDING LENGTH OF FIRST STRING
    int num2Len = num2.length();//FINDING LENGTH OF SECOND STRING
    for (int i = 0; i < num1Len; i++)//LOOP FOR PUSHING FIRST STRING CHARACTERS TO A STACK 
    {
        pushF(num1[i]);
    }
    for (int i = 0; i < num2Len; i++)//LOOP FOR PUSHING SECOND STRING CHARACTERS TO A STACK 
    {
        pushS(num2[i]);
    }
    int totalLen = num1Len + num2Len;//CALCULATING TOTAL LENGTH BY TAKING SUM OF LENGTH OF FIRST AND SECOND STRING
    merge(totalLen);//CALLING MERGE FUNCTIONAND PASSING VALUE OF TAOTAL LENGTH
    for (int i = 0; i < totalLen; i++)//AFFTER STORING BOTH STRINGS ALTERNATELY IN THIRD STRING USING A LOOP TO POP VALUES PUSHED IN THIRD STRING AND PRINTING IT
    {
        cout << pop() << " ";
    }
}