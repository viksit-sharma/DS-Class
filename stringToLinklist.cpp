#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
    char data;
    node *next;
};

node *first, *temp, *ttemp, *p,*q,*t;

void init(){
    first = ttemp = temp = NULL;
}

void createFirstNode(char x){
    first = new node;
    first->data = x;
    first->next = NULL;
}

void addNode(char x){
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
    cout << "The elements of link list are : ";
    while(temp!=NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

int checkPal(){
    temp = first;
    char arr[9];
    for (int i = 0; temp!=NULL ;i++){
        arr[i] = temp->data;
        temp = temp->next;
    }
    int i = 0;
    while(i<5){
        if(arr[i]!=arr[8-i]){
            return -1;
        }
        i++;
    }
    return 1;
}

int main(){
    
    char str[] = "MalayalaM";

    createFirstNode(str[0]);

    for (int i = 1; i < 10;i++){
        addNode(str[i]);
    }

    display();

    int result = checkPal();

    if(result==1){
        cout<<("Is Palindrome !!!");
    }
    else{
        cout<<("Is not plaindrome !!!");
    }
}