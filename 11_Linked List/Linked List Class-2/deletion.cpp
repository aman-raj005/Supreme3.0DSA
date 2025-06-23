 // MY CODE 
 #include<iostream>
using namespace std;
class Node{
    public:
    //attributes
    int data;
    Node* next;
    Node* prev;
    
    //construcotr
    Node(int value){
        this->data=value;
        this->next=NULL;
        this->prev=NULL;
    }
};

    void insertAtHead(int value,Node* &head,Node* &tail){
        if(head==NULL && tail==NULL)
         {
           Node* newNode=new Node(value);
           head=newNode;
           tail=newNode;
           
         }
         else{
           Node* newNode=new Node(value);
           newNode->next=head;
           head=newNode;
           Node*  nextnode=newNode->next;
           nextnode->prev=newNode;
         }
    };
    void insertattail(int value,Node* &head,Node* &tail)
     {
        if(head==NULL && tail==NULL){
            Node* newNode=new Node(value);
            head=newNode;
            tail=newNode;
        }
        else{
            Node* newNode=new Node(value);
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;

        }
     }
    void print(Node* head){
        Node* temp=head;
        while(temp !=NULL){
           cout<<temp->data<<"  ";
           temp=temp->next;
        }
        cout<<endl;
    };
    void printreverse(Node* tail){
        Node* temp=tail;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }
    int getlength(Node* head){
        int len=0;
        Node* temp=head;
        while(temp != NULL){
            temp=temp->next;
            len++;
        }
      return len;
    }
    void inserstanypositon(int position,int value,Node* &head,Node* &tail){
        int length=getlength(head);
        if(position==1){
          insertAtHead(value,head,tail);
        }
        else if(position==length+1){
           insertattail(value,head,tail); 
        }
        else{
            Node* prevNode =head;
            for(int i=1;i<position;i++){
                prevNode =prevNode ->next;
            }
            Node* newNode=new Node(value);
            Node* nextNode=prevNode->next;
            prevNode ->next=newNode;
            newNode->prev=prevNode ;
            nextNode->prev=newNode;
            newNode->next=nextNode;
        }
    }
    bool searching(Node*head,int target){
        Node* temp=head;
        while(temp !=NULL){
            if(temp->data==target){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    void deletinganyposition(int position,Node* &head,Node* &tail){
        int len=getlength(head);
        if(head==NULL &&tail==NULL){
            cout<<"delecton is not possile"<<endl;
        }
        else if(head==tail){
            Node* temp=head;
            head=NULL;
            tail=NULL;
            delete temp;
        }
        else if(position==1){
            Node* temp=head;
            Node* firstnode=temp->next;
            head=firstnode;
            firstnode->prev=NULL;
            temp->prev=NULL;
            temp->next=NULL;
        }
        else if(position==len){
            Node* temp=tail;
            Node* lastnode=temp->prev;
            tail=lastnode;
            lastnode->next=NULL;
            temp->prev=NULL;
            temp->next=NULL;
            
            delete temp;

        }
        else{
            Node* temp=head;
            //go to that node
            for(int i=1;i<position;i++){
                temp=temp->next;
            }
            //naming next node
            Node* nextNode=temp->next;
            Node* prevNode=temp->prev;
            prevNode->next=nextNode;
            nextNode->prev=prevNode;
            temp->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
    }
int main(){
  Node* head=NULL;
  Node* tail=NULL;
  insertAtHead(44,head,tail);
//   print(head);
   insertAtHead(33,head,tail);
//   print(head);
    insertAtHead(22,head,tail);
    // print(head);
//   printreverse(tail);
insertattail(55,head,tail);
inserstanypositon(1,11,head,tail);
inserstanypositon(6,66,head,tail);
inserstanypositon(1,00,head,tail);
cout<<searching(head,5)<<endl;
deletinganyposition(2,head,tail);
print(head);
    return 0;
}



// CODE BY LOVE BABBAE 

#include<iostream>
using namespace std;
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    //constructor
    Node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(int value, Node* &head, Node* &tail){
    //LL is empty
    if(head==NULL & tail==NULL){
        Node* newNode = new Node(value);
        head= newNode;
        tail = newNode;
    }
    else{
        // LL is not empty
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(int value, Node* &head, Node* &tail){
    if(head == NULL && tail == NULL){
        //LL is empty
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is not empty
        Node* newNode = new Node(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtPosition(int position, int value,Node* &head, Node* &tail){
    int len = getLength(head);
    if(position==1){
        insertAtHead(value,head,tail);
    }
    else if(position==len+1){
        insertAtTail(value,head,tail);
    }
    else{
        //insert in middle of LL
        Node* temp = head;
        for(int i =0 ; i<position-2;i++){
            temp = temp->next;
        }
        // create node
        Node* newNode = new Node(value);
        // forward pointer set
        Node* forward = temp->next;
        // pointers ko set krdo
        newNode->prev = temp;
        temp->next = newNode;
        forward->prev = newNode;
        newNode->next = forward;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteFromPosition(int position, Node* &head, Node* &tail){
    int len = getLength(head);
    // LL is empty
    if(head == NULL && tail == NULL){
        cout<<"no node to delete";
    }
    else if(head == tail){
        //single node
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else if(position==1){
        //delete Head node
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if(len == position){
        Node* temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else{
        //delete node other than head
        Node* backward = head;
        for(int i=0; i<position-2;i++){
            backward = backward->next;
        }
        Node* curr = backward->next;
        Node* forward = curr->next;

        // pointers change
        backward->next = forward;
        forward->prev = backward;
        // isolate curr
        curr->prev = NULL;
        curr->next = NULL;
        
        delete curr;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(10,head,tail);
    insertAtTail(20,head,tail);
    insertAtTail(30,head,tail);
    print(head);

    insertAtPosition(3,420,head,tail);
    print(head);

    deleteFromPosition(4,head,tail);
    print(head);
    return 0;
}
