// Reverse a number using stack
#include <iostream>
#include <math.h>
using namespace std;
struct stack
{
    char data;
    stack *next;
};
stack *top, *temp;
void init()
{
    top = temp = NULL;
}
void push(char x)
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
int reverse(int numTemp)
{
    int num = 0; // initiallised num by zero because we will add the number in it to form the reverse
    int j = 1;   // initaillised j by 1 because we will multiply it to the number we will pop to make the number reverse like at first 1 will come so one will be stored in num as it is because num=0, then 2 will come so we will increase j by multuplying it to 10 so 2*10=20 then added to 1 means 20+1=21 i.e. reverse of 12, in this way we will reverse the number
    for (int i = 0; numTemp > 0; i++)
    {
        num = num + pop() * j; // adding num to the multiplication of popped value with j to make reverse number
        numTemp /= 10; // dividing numTemp by 10 to make the numTemp smaller to reach termianting condition i.e. numTemp>0
        j *= 10; // increasing j as a multiplier of 10
    }
    return num; // returning  reverse value
}
int main()
{
    int num;
    cout << "Enter number to reverse : ";
    cin >> num;
    int numTemp = num; // stored value of num in numTemp variable to use it later
    while (num > 0)
    {
        push(num % 10); // pushing the remainder of num%10 to the stack
        num /= 10; // dividing num by 10 to make the num smaller to reach termianting condition i.e. num>0
    }
    num = reverse(numTemp); // passed value of num stored in numTemp to reverse() function;
    cout << num;
}