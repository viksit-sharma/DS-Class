// Ques 1.) Check wheather a input string is palindrome or not using stack
#include <iostream>
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
bool isPalindrome()
{
    int len = 0; // initiallised length with zero

    while (temp != NULL) // Used a loop to calculate the (len)length of stack to create an character array of that size
    {
        len++;
        temp = temp->next;
    }
    char arr[len];                // created character array of size equals to (len)length
    for (int i = 0; i < len; i++) // used a loop to pop values from the stack and stored it in the character array we made, runs until i!=len
    {
        arr[i] = pop(); // popping elements from stack and assigning it to char arr at index i
    }
    int i = 0;           // initiallised i by 0 because we will use it in while loop to check wheather the element that are popped and stored in char aaray are palindrome or not
    while (i <= len / 2) // created a loop that runs till mid of the array length because we will compare the two half parts of array together
    {
        if (arr[i] != arr[len - 1 - i]) // if the element at positon i from starting is not same as the element at position i from ending then we will return false because our string is not palindrome
        {
            return false;
        }
        i++; // incrementing i by one to move index to next element
    }
    return true; // if the while loop is terminated this means all the elements are same at ith potion from start and end means its palindrome so we will return true
}
int main()
{
    string str;
    cout << "Enter a string to check its palindrome or not: ";
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        push(str[i]); // pushing elements of string to stack
    }
    bool res = isPalindrome(); // calling is palindrome function and storing its value in res(variable) of type bool
    if (res) // if res==true the if works otherwise else works
    {
        cout << "Is palindrome";
    }
    else
    {
        cout << "Is not palindrome";
    }
}