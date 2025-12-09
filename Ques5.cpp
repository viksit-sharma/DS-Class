// Convert the polynomial list in the form of two separate stack in which one istake will contain all the power fields and another stack will contain all the  coefficient field
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
void separate(string str)
{ // x4+4x3+x2+5x+1
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+')
        {
            continue;
        }
        else if (str[i] == 'x' && i == 0)
        {
            pushS('1');
            if (str[i + 1] >= 48 && str[i + 1] <= 57)
            {
                pushF(str[i + 1]);
            }
        }
        else if (str[i] == 'x')
        {
            if (str[i + 1] >= 48 && str[i + 1] <= 57)
            {
                pushF(str[i + 1]);
            }
            else if (str[i + 1] == '+')
            {
                pushF('1');
            }
            if (str[i - 1] >= 48 && str[i - 1] <= 57)
            {
                pushS(str[i - 1]);
            }
            else if (str[i - 1] == '+')
            {
                pushS('1');
            }
        }
        else if (str[i] != '+' && str[i] != 'x' && i > 0 && str[i] >= 48 && str[i] <= 57 && i == str.length() - 1)
        {
            pushS(str[i]);
            pushF('0');
        }
    }
}
int main()
{
    string alpNum;
    cout << "Enter a polynomial string : ";
    cin >> alpNum;
    separate(alpNum);
    char pop[alpNum.length()];

    int count = 1;
    for (int i = 0; i < alpNum.length(); i++)
    {
        if (alpNum[i] == '+')
        {
            count++;
        }
    }
    char arrF[count];
    char arrS[count];
    for (int i = 0; i < count; i++)
    {
        arrF[i] = popF();
        arrS[i] = popS();
    }
    cout << "Powers are : ";
    for (int i = count - 1; i >= 0; i--)
    {
        cout << arrF[i] << " ";
    }
    cout << endl
         << "Coefficients are : ";
    for (int i = count - 1; i >= 0; i--)
    {
        cout<< arrS[i] << " ";
    }
}