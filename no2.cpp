#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct node1{
    char data;
    node1 *next;
};
node1 *first1, *temp1, *ttemp1, *p1,*q1,*t1;
void init1(){
    first1 = ttemp1 = temp1 = NULL;
}
void createFirstnode1(char x){
    first1 = new node1;
    first1->data = x;
    first1->next = NULL;
}
void addnode1(char x){
    temp1 = first1;
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    ttemp1 = new node1;
    ttemp1->next = NULL;
    ttemp1->data = x;
    temp1->next = ttemp1;
}
void display1(){
    temp1 = first1;
    while(temp1!=NULL){
        cout << temp1->data<<endl;
        temp1 = temp1->next;
    }
}
struct node2{
    char data;
    node2 *next;
};
node2 *first2, *temp2, *ttemp2, *p2,*q2,*t2;
void init2(){
    first2 = ttemp2 = temp2 = NULL;
}
void createFirstnode2(char x){
    first2 = new node2;
    first2->data = x;
    first2->next = NULL;
}
void addnode2(char x){
    temp2 = first2;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    ttemp2 = new node2;
    ttemp2->next = NULL;
    ttemp2->data = x;
    temp2->next = ttemp2;
}

void display2(){
    temp2 = first2;
    while(temp2!=NULL){
        cout << temp2->data<<endl;
        temp2 = temp2->next;
    }
}
int compare(){
    temp1 = first1;
    temp2 = first2;
    temp2 = temp2->next;
    while(temp1!=NULL&&temp2!=NULL){
        char a = temp1->data;
        char b = temp2->data;
        if(a!=b){
            return -1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 1;
}
int main()
{
    char str[] = "DAD";

    createFirstnode1(str[0]);

    for (int i = 1; i < strlen(str)+1;i++){
        addnode1(str[i]);
    }
    char rev[9];
    for (int i = strlen(str) ,j=0; i > -1;i--,j++){
        rev[i] = str[j];
    }
    // display1();
    createFirstnode2(rev[0]);

    for (int i = 1; i < strlen(str)+1;i++){
        addnode2(rev[i]);
    }
    // display2();
    
    int result = compare();
    if(result==1){
        printf("Is Palindrome !!!");
    }
    else{
        printf("Is not plaindrome !!!");
    }
}