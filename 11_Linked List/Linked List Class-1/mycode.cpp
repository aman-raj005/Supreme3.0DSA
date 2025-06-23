#include<iostream>
using namespace std;
  class Node{
    public:
    //attribute
    int data;
    Node* next;
    //constructor
    Node (int value){
        this->data=value;
        this->next=NULL;
    }
  };
  Node* insertAtHead(int value , Node* &head ,Node* &tail){
        if(head==NULL && tail==NULL){
            Node* newNode=new Node(value);
            head=newNode;
            tail=newNode;
        }
        else{
            Node* newNode=new Node(value);
            newNode->next=head;
            head=newNode;
        }
    return head;
  }
   Node* insertAtTail(int value , Node* &head ,Node* &tail){
        if(head==NULL && tail==NULL){
            Node* newNode=new Node(value);
            head=newNode;
            tail=newNode;
        }
        else{
            Node* newNode=new Node(value);
            tail->next=newNode;
            tail=newNode;
        }
    return head;
  }
  int getlength(Node* head){
     Node* temp=head;
     int len=0;
     while(temp != NULL){
      temp=temp->next;
      len++;
     }
     return len;
  }
  Node* InserataPosition(int position,int value , Node* &head ,Node* &tail){
     int length=getlength(head);
     if(position==1){
        head=insertAtHead(value,head,tail);
     }
     else if(position==length+1){
        head=insertAtTail(value,head,tail);
     }
     else{
        Node* temp=head;
        for(int i=0;i<position-2;i++){
            temp=temp->next;
        }
         Node* newNode=new Node(value);
         newNode->next=temp->next;
         temp->next=newNode;
     }
     return head;
  }
  void print(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<endl;
  }
  bool search(Node* head,int target){
    Node* temp=head;
    while(temp != NULL){
      if(temp->data==target){
        return true;
      }
      temp=temp->next;
    }
    return false;
  }
int main(){
    //create a linkedlist
    Node* head=NULL;
    Node* tail=NULL;

    //insert at head
    head=insertAtHead(44,head,tail);
    // print(head);
     head=insertAtHead(45,head,tail);
    // print(head);
     head=insertAtHead(46,head,tail);
    // print(head);
    head=insertAtTail(47,head,tail);
    // print(head);
    head=InserataPosition(2,99,head,tail);
    print(head);
    cout<<search(head, 4)<<endl;
    
  return 0;
}