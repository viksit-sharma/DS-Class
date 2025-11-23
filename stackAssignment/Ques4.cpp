// Given a string containing alpha numeric values create two stack one stack would store all the numeric values of that string and other stack would store all the alphabets from that string
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
void separateIntoAlphaAndNum(string str)//SEPARATES NUMBERS AND ALPHABETS
{
    for (int i = 0; i < str.length(); i++)//RUNNING LOOP FROM I = 0 TO STRING LENGTH-1 
    {
        if (str[i] >= 97 && str[i] <= 122 || str[i] >= 65 && str[i] <= 90)//IF CHARACTER AT INDEX I IS APLHABET EITHER UPPERCASE OR LOWERCASE PUSHING IT IN FIRST STACK
        {
            pushF(str[i]);
        }
        else//IF CHARACTER AT INDEX I IS NOT APLHABET MEANS NUMBER THEN PUSHING IT IN SECOND STACK
        {
            pushS(str[i]);
        }
    }
}
int main()
{
    string alpNum;
    cout << "Enter a alphanumeric string : ";//TAKING INPUT IN ALPNUM STRING VARIABLE
    cin >> alpNum;
    separateIntoAlphaAndNum(alpNum);//CALLING SEPARATE FUNTION TO SEPERATE THE ALPHANUMERIAC STRING INTO ALPHABETS AND NUMBERS AND PASSING ALPNUM STRING IN IT
    cout << "Alphabets are : ";
    while (topF != NULL)// PRINTS ALPHABETS THAT WERE STORED IN FIRST STACK BY POPPING THEM
    {
        cout << popF();
    }
    cout << endl
         << "Numbers are : ";
    while (topS != NULL)// PRINTS NUMBERS THAT WERE STORED IN SECOND STACK BY POPPING THEM
    {
        cout << popS();
    }
}