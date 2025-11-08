#include <iostream>
using namespace std;

struct node{
  int data;
  node *next;
};

node *first , *temp , *ttemp, *p, *ptemp, *ntemp ;

void init(){
  first=temp=ttemp=NULL;

}

void create_first(int x){
  first = new node;
  first -> next = NULL;
  // cout<<"enter data for first node : ";
  // cin>>first->data;
  first->data=x;
}

void add_node(int x){
  temp=first;
  while(temp -> next !=NULL){
    temp=temp -> next;
  }
  ttemp=new node;
  ttemp -> next =NULL;
  ttemp->data=x;
  temp -> next =ttemp;
}

void display(){
  temp = first;
  while(temp !=NULL){
  cout<<temp -> data<<endl;
  temp=temp->next;
  }
}

void add_After(int x , int y){
  temp =first;
  while(temp -> data != x){
    temp = temp -> next; 
  }
  ttemp = temp-> next;
  p = new node;
  p->data=y;
  temp ->next = p;
  p-> next= ttemp;
}

void add_Before(int x , int y){
  temp=first;
  ttemp=temp->next;
  while(ttemp->data!=x){
    ttemp=ttemp->next;
    temp=temp->next;
  }
  /*or we can do
    temp=first;
    while(temp->data!=x){
      ttemp=temp
      temp=temp->next
    } */
  p = new node;
  p->data=y;
  temp ->next = p;
  p-> next= ttemp;

}

void add_Before_First(int x){
  temp =new node;
  temp->data=x;
  temp->next=first;
  first=temp;
}

void add_Before_Last(int y){
  temp=first;
  //ttemp=temp->next;
  while(ttemp->next!=NULL){
    // ttemp=ttemp->next;
    // temp=temp->next;
    ttemp=temp;
    temp=temp->next;
  }
  p = new node;
  p->data=y;
  temp ->next = p;
  p-> next= ttemp;
}  
void del_After(int x){
  temp = first;
  while(temp->data!=x){
    temp = temp->next;
  }
    ttemp = temp->next;
    p=ttemp->next;
    temp->next=p;
    ttemp-> next= NULL;
    delete ttemp;
}

void del_Before(int x){
  temp=first;
  while(temp->next->data!=x){
    ttemp=temp;
    temp=temp->next;
  }
  p=temp->next;
  ttemp->next=p;
  temp->next=NULL;
  delete temp;
}

  void reverse(){
    temp = first;
    ptemp=NULL;
    ntemp=temp->next;
    while(temp->next !=NULL){
      temp->next=ptemp;
      ntemp->next=temp;
      ptemp=temp;
      temp=ntemp;
      ntemp=ntemp->next;
    }
    first=temp;
  }

  void del_Sec_Last(){
  temp=first;
  while(temp->next->next!=NULL){
    ttemp=temp;
    temp=temp->next;
  }
  p=temp->next;
  ttemp->next=p;
  temp->next=NULL;
  delete temp;
}

void swap12(){
  temp=first;
  ttemp=temp->next;
  p=ttemp->next;
  ttemp->next=temp;
  temp->next=p;
  first=ttemp;
}

void swapfl(){
  temp=first;
  while(ttemp->next!=NULL){
    ttemp=temp;
    temp=temp->next;
  }
  ttemp->next=temp;
  temp->next=NULL;
  first=ttemp;
}


int main(){
  init();
  create_first(10);
  add_node(20);
  add_node(30);
  add_node(40);
  add_node(50);
  add_node(60);
  display();
  cout<<endl;
  display();
  return 0;
}