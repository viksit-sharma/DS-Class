// Convert the polynomial list in the form of two separate stack in which one istake will contain all the power fields and another stack will contain all the coefficient field
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
void separateIntoPowAndCoeff(string str)
{ 
    for (int i = str.length() - 1; i >= 0; i--)//RUNNING FOR LOOP FORM I = STRING LENGTH-1 TO 0
    {
        if (str[i] == '+')//IF STR OF INDEX I IS CHARACTER '+' THEN WE WILL CONTINUE/SKIP TO NEXT ITERATION 
        {
            continue;
        }
        else if (str[i] == 'x' && i == 0)//IF STR OF INDEX I IS CHARACTER 'x' AND ITS AT ZEROTH INDEX THEN WE WILL PUSH '1' IN STACK FOR COEFFICENT BECAUSE NOTHING CAN BE THERE BEFORE ZEROTH INDEX
        {
            pushS('1');
            if (str[i + 1] >= 48 && str[i + 1] <= 57)//IF STR AT INDEX I+1 IS ANY NUMBER PUSHING VALUE OF STR AT INDEX I+1 IN STACK FOR POWER
            {
                pushF(str[i + 1]);
            }
        }
        else if (str[i] == 'x')//IF STR OF INDEX I IS CHARACTER 'x' THEN WE WILL CHECK :
        {
            if (str[i + 1] >= 48 && str[i + 1] <= 57)//IF NEXT ELEMENT AFTER 'x' IS A NUMBER THEN WE WILL PUSH IT IN THE POWER STACK
            {
                pushF(str[i + 1]);
            }
            else if (str[i + 1] == '+')//IF NEXT ELEMENT AFTER 'x' IS CHARACTER '+' THEN WE WILL PUSH '1' IN POWER STACK
            {
                pushF('1');
            }
            if (str[i - 1] >= 48 && str[i - 1] <= 57)//IF PREVIOUS ELEMENT BEFORE 'x' IS NUMBER THEN WE WILL PUSH THAT VALUE OF NUMBER IN COEFFICIENT STACK
            {
                pushS(str[i - 1]);
            }
            else if (str[i - 1] == '+')//IF PREVIOUS ELEMENT BEFORE 'x' IS CHARACTER '+' THEN WE WILL PUSH '1' IN COEFFICIENT STACK
            {
                pushS('1');
            }
        }
        else if (str[i] != '+' && str[i] != 'x' && i > 0 && str[i] >= 48 && str[i] <= 57 && i == str.length() - 1) // IF THE VALUE OF STR OF I IS NOT '+' , NOT 'x' , BUT A NUMBER AND VALUE OF I IS EQUAL TO THE LAST POSSIBLE INDEX VALUE THEN PUSH '0' IN POWER STACK AND THE VALUE OF NUMBER IN COEFFICENT STACK
        {
            pushS(str[i]);
            pushF('0');
        }
    }
}
int main()
{
    string polynomial;
    cout << "Enter a polynomial string : ";//TAKING INPUT FOR STRING POLYNOMIAL
    cin >> polynomial;
    separateIntoPowAndCoeff(polynomial);//CALLING SEPARATE INTO POWER AND COEFFICENT FUNTION TO SEPARATE THE VALUES OF POWER AND COEFFICIENT INTO TWO DIFFERENT STACKS AND PASSING POLYNOMIAL STRING
    cout << "Powers are : ";
    while (topF != NULL)//PRINTING POWERS BY POPPING IT FROM THE POWER STACK
    {
        cout << popF() << " ";
    }
    cout << endl
         << "Coefficents are : ";
    while (topS != NULL)//PRINTING COEFFICENTS BY POPPING IT FROM THE COEFFICENT STACK
    {
        cout << popS() << " ";
    }
}