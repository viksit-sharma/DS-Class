#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct stackOpr
{
    string data;
    stackOpr *next;
};
stackOpr *topOpr, *tempOpr;
void initOpr()
{
    topOpr = tempOpr = NULL;
}
void pushOpr(string x)
{
    tempOpr = new stackOpr;

    if (tempOpr == NULL)
    {
        return;
    }
    tempOpr->data = x;
    tempOpr->next = topOpr;
    topOpr = tempOpr;
    // cout << "pushed" << x<<endl;
}
string popOpr()
{
    string x;
    if (topOpr == NULL)
    {
        return "";
    }
    x = topOpr->data;
    tempOpr = topOpr;
    topOpr = topOpr->next;
    tempOpr->next = NULL;
    delete tempOpr;
    // cout << "popped" << x << endl;
    return x;
}
struct stackOpd
{
    string data;
    stackOpd *next;
};
stackOpd *topOpd, *tempOpd;
void initOpd()
{
    topOpd = tempOpd = NULL;
}
void pushOpd(string x)
{
    tempOpd = new stackOpd;

    if (tempOpd == NULL)
    {
        return;
    }
    tempOpd->data = x;
    tempOpd->next = topOpd;
    topOpd = tempOpd;
    // cout << "pushed" << x<<endl;
}
string popOpd()
{
    string x;
    if (topOpd == NULL)
    {
        return "";
    }
    x = topOpd->data;
    tempOpd = topOpd;
    topOpd = topOpd->next;
    tempOpd->next = NULL;
    delete tempOpd;
    // cout << "popped" << x << endl;
    return x;
}

string infixToPrefix(string str)
{
    string str1, str3, str2, str4, str5;
    // reverse(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            pushOpr(string(1, str[i]));
            // cout << "1 pushed " << str[i] << endl;
        }
        else if (str[i] >= 97 && str[i] <= 122)
        {
            pushOpd(string(1, str[i]));
            // cout << "2 pushed " << str[i] << endl;
        }
        else if (str[i] == '^')
        {
            while (topOpr->data != "+" && topOpr->data != "-" && topOpr->data != "*" && topOpr->data != "/" && topOpr->data !="(")//EK BHI FALSE HUA TOH LOOP BREAK
            {
                str3 = popOpr();
                str1 = popOpd();
                str2 = popOpd();
                str4 = str2 + str1;
                str5 = str3 + str4;
                pushOpd(str5);
                // cout << "3 pushed " << str5 << endl;
            }
            pushOpr(string(1, str[i]));
            // cout << "4 pushed " << str[i] << endl;
        }
        else if (str[i] == '*' || str[i] == '/')
        {
            while (topOpr->data != "+" && topOpr->data != "-" && topOpr->data !="(")//EK BHI FALSE HUA TOH LOOP BREAK
            {
                str3 = popOpr();
                str1 = popOpd();
                str2 = popOpd();
                str4 = str2 + str1;
                str5 = str3 + str4;
                pushOpd(str5);
                // cout << "5 pushed " << str5 << endl;
            }
            pushOpr(string(1, str[i]));
            //  cout << "6 pushed " << str[i] << endl;
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            while (topOpr->data != "(")
            {
                str3 = popOpr();
                str1 = popOpd();
                str2 = popOpd();
                str4 = str2 + str1;
                str5 = str3 + str4;
                pushOpd(str5);
                // cout << "7 pushed " << str5 << endl;
            }
            pushOpr(string(1, str[i]));
            //  cout << "8 pushed " << str[i] << endl;
        }
        else if (str[i] == ')')
        {
            while (topOpr->data != "(")
            {
                str3 = popOpr();
                str1 = popOpd();
                str2 = popOpd();
                str4 = str2 + str1;
                str5 = str3 + str4;
                pushOpd(str5);
                // cout << "9 pushed " << str5 << endl;
            }
            string bin = popOpr();
        }
    }
    return topOpd->data;
}
int main()
{
    initOpd();
    initOpr();
    cout << infixToPrefix("(a+(b/c)*(d^e)-f)");
}