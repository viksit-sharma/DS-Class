#include <iostream>
#include <stdio.h>
using namespace std;
struct node{
    int data;
    node *next;
};
node *first, *temp, *ttemp, *p,*q,*t;
void init(){
    first = ttemp = temp = NULL;
}
void createFirstNode(int x){
    first = new node;
    first->data = x;
    first->next = NULL;
}
void addNode(int x){
    temp = first;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    ttemp = new node;
    ttemp->next = NULL;
    ttemp->data = x;
    temp->next = ttemp;
}
void display(){
    temp = first;
    while(temp!=NULL){
        cout << temp->data<<endl;
        temp = temp->next;
    }
}

int main()
{
    int num;
    cout << "Enter a number : ";
    cin >> num;
    int tNum = num;
    int rev = 0;
    while (num > 0)
    {
        int lastDig = num % 10;
        rev = rev * 10 + lastDig;
        num = num / 10;
    }
    int first = rev % 10;
    rev = rev / 10;//8764
    createFirstNode(first);
    for (int i = 0; rev > 0; i++)
    {
        addNode(rev % 10);
        rev /= 10;
    }
    display();
}