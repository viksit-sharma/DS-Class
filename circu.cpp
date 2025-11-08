#include <iostream>
using namespace std;
struct node{
    int data;
    node *next, *prev;
};

node *temp, *ttemp, *first, *p;

void createFirst(){
    first = new node;
    cin >> first->data;
    first->next = NULL;
    first->prev = NULL;
}

void addNode(){
    temp=first;
    while(temp->next!=NULL){
        temp = temp -> next;
    }
    ttemp = new node;
    cin >> ttemp->data;
    ttemp->prev = temp;
    ttemp->next = first;
    temp->next = ttemp;
    first->prev = ttemp;
}

void display(){
    temp = first;
    while(temp!=NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    createFirst();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    display();
}