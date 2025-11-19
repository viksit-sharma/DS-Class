#include <iostream>
using namespace std;
struct node{
    int data;
    node *next, *prev;
};
node *temp, *ttemp, *first, *p, *secondLast,*last;

void createFirst(int x){
    first = new node;
    first->data=x;
    first->next = first;
    first->prev = first;
}
void addNode(int x){
    temp=first;
    while(temp->next!=first){
        temp = temp -> next;
    }
    ttemp = new node;
    ttemp->data=x;
    ttemp->prev = temp;
    ttemp->next = first;
    first->prev = temp->next = ttemp;
}
void addBefore(int x,int y){
    temp = first;
    while(temp->data!=x){
        temp = temp->next;
    }
    p = temp->prev;
    ttemp = new node;
    ttemp->data = y;
    ttemp->next = temp;
    ttemp->prev = p;
    p->next = ttemp;
    temp->prev = ttemp;
}
void addAfterLast(int x){
    temp = first;
    while(temp->next!=first){
        temp = temp->next;
    }
    p = new node;
    p->data = x;
    p->next = temp->next;
    p->prev = temp;
    temp->next = p;
    first->prev = p;
}
void addAfter(int x,int y){
    temp = first;
    while(temp->data!=x){
        temp = temp->next;
    }
    ttemp = temp->next;
    p = new node;
    p->data = y;
    p->next = ttemp;
    p->prev = temp;
    temp->next = p;
    ttemp->prev = p;
}
void delBefore(int x){
    temp = first;
    while(temp->next->data!=x){
        temp=temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = temp->prev = NULL;
    delete temp;
}
void deleteNth(int x){
    temp = first;
    while(temp->data!=x){
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->next = temp->prev = NULL;
    delete temp;
}
void swapLastSecondlast(){
    temp = first;
        temp = temp->prev->prev;
    secondLast = temp;
    last = temp->next;
    secondLast->prev->next=last;
    last->prev = secondLast->prev;
    last->next = secondLast;
    secondLast->prev = last;
    secondLast->next = first;
    first->prev = secondLast;
}
void swapFirstSecond(){
    temp = ttemp = first;
    while(ttemp->next!=first){
        ttemp = ttemp->next;
    }
    temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev->prev = temp;
    temp->prev = first->prev;
    temp->next = first;
    first = temp;
    ttemp->next = first;
}
void delAfter(int x){
    temp = first;
    while(temp->data!=x){
        temp = temp->next;
    }
    ttemp = temp->next;
    temp->next = ttemp->next;
    ttemp->next->prev = temp;
    ttemp->next = NULL;
    ttemp->prev = NULL;
    delete ttemp;
}
void addNodeBeforeFirst(int x){
    temp =p= first;
    p = p->next;
    ttemp = new node;
    ttemp->next = first;
    ttemp->data = x;
    ttemp->prev = p;
    temp->prev = ttemp;
    first = ttemp;
    p->next = first;
}
void swapMthAndNth(int m,int n){
    temp = first;
    ttemp = first;
    for (int i = 1; i < m;i++){
        temp = temp->next;
    }
    for (int i = 1; i < n;i++){
        ttemp = ttemp->next;
    }
    temp->prev->next = ttemp;
    ttemp->prev->next = temp;
    temp->next->prev = ttemp;
    ttemp->next->prev = temp;
    p = temp->prev;
    node *next = temp->next;
    temp->next = ttemp->next;
    temp->prev = ttemp->prev;
    ttemp->next = next;
    ttemp->prev = p;
}
void display(){
    temp = first;
    do{
        cout << temp->data<<" ";
        temp = temp->next;
    } while (temp!= first);
}
int main() {
    createFirst(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);
    addNode(7);
    addNode(8);
    addNode(9);
    addNode(10);
    swapLastSecondlast();
    // swapFirstSecond();
    // addNodeBeforeFirst(0);
    // addAfterLast(11);
    // swapMthAndNth(3, 8);
    // delAfter(8);
    // deleteNth(7);
    // delBefore(9)
    // addAfter(9,11);
    // addBefore(10, 11);
    // addBeforeFirst(0);
    display();
}