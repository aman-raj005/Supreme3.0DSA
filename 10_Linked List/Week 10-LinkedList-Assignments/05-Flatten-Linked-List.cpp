// gfg: Flatttening a Linked List

// my code            https://youtu.be/ykelywHJWLg?feature=shared


/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/
  
class Solution {
  public:
     Node* funflat(Node* headnode,Node* temp)
      {
         Node* dummynode=new Node(-1);
         Node* res=dummynode;
         while(headnode && temp)
          {
            if(headnode->data <=temp->data)
               {
                dummynode->bottom=headnode;
                dummynode->next=NULL;
                headnode=headnode->bottom;
               } 
            else{
                dummynode->bottom=temp;
                dummynode->next=NULL;
                temp=temp->bottom;
                }
              dummynode=dummynode->bottom;
          }
         if(headnode){dummynode->bottom=headnode;}
         else if(temp ){dummynode->bottom=temp; }
         dummynode->next=NULL;
         return res->bottom;
      }
  
    Node *flatten(Node *head) {
        Node* temp=head;
        //base case
        if(head==NULL || head->next==NULL){return head; }
        // Your code here
        Node* headnode=flatten(head->next);
        
      return funflat(headnode,temp);
    }
};


  //  code by stiber 

// Node structure for the special linked list
struct Node {
    int data;
    Node* next;
    Node* child;

    Node(int x) : data(x), next(nullptr), child(nullptr) {}
};

/*
 * Function to merge two sorted linked lists (using child pointers)
 * This is an iterative merge using a dummy node.
 */
Node* merge(Node* list1, Node* list2) {
    // Create a dummy node to start building the merged list
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    // Merge the two lists while both have nodes
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            res->child = list1;          // Attach list1 node
            list1 = list1->child;        // Move list1 down
        } else {
            res->child = list2;          // Attach list2 node
            list2 = list2->child;        // Move list2 down
        }
        res = res->child;                // Advance res to newly added node
        res->next = nullptr;            // Ensure next pointer is null in flattened list
    }

    // Attach any remaining nodes from list1 or list2
    if (list1) res->child = list1;
    else res->child = list2;

    // Safety: Ensure the 'next' of the entire flattened list is null
    if (dummyNode->child) dummyNode->child->next = nullptr;

    // Return the head of the merged list (skipping dummy node)
    return dummyNode->child;
}

/*
 * Function to flatten the special 2D linked list into a single sorted linked list
 * using only child pointers
 */
Node* flattenLinkedList(Node* head) {
    // Base case: if the list is empty or there's only one horizontal list
    if (head == nullptr || head->next == nullptr) return head;

    // Recursively flatten the list to the right
    Node* mergedHead = flattenLinkedList(head->next);

    // Merge the current vertical list with the flattened right side
    head = merge(head, mergedHead);

    // Return the fully flattened list starting at head
    return head;
}


  //                             code by lakchyaa 
/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
public:
	Node*merge(Node*a, Node*b){
		if(!a) return b;
		if(!b) return a;
		Node* ans = 0;
		if(a->data < b->data){
			ans = a;
			a->bottom = merge(a->bottom, b);
		}
		else{
			ans = b;
			b->bottom = merge(a, b->bottom);
		}
		return ans;
	}
    Node *flatten(Node *root)
    {
        if(!root) return 0;
		Node* mergedLL = merge(root, flatten(root->next));
		return mergedLL;
    }
};
