// gfg: Binary Tree to DLL

                                      //       https://youtu.be/7bGnF5eILKw?feature=shared
 // my code 
 
 
 /* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution {
  public:
  void inorder(Node* current ,Node* &head,Node* &prev ){
      if(current==NULL ){return ;}
      inorder( current->left , head,prev ) ;
      if(head==NULL){ head=current ;  }
      else{
          prev->right=current;
          current->left=prev;
      }
      prev=current;
      inorder( current->right , head,prev ) ;
  }
    Node* bToDLL(Node* root) {
        // code here
        Node* head=NULL;
        Node* prev=NULL;
        inorder(root ,head,prev );
        return head;
    }
};
 
 
 
 
 
   // my second code 
 
 
 // Definition of the binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* head = NULL; // Head of the resulting doubly linked list
    Node* prev = NULL; // Pointer to keep track of the previous visited node

    // Recursive function to perform inorder traversal and convert to DLL
    void rec(Node* curr) {
        if (curr == NULL)
            return;

        // Step 1: Recurse on the left subtree
        rec(curr->left);

        // Step 2: Process current node
        if (head == NULL) {
            // First node (leftmost) becomes the head of the DLL
            head = curr;
        } else {
            // Link the current node with the previous node in DLL fashion
            prev->right = curr; // previous node's right points to current
            curr->left = prev;  // current node's left points to previous
        }

        // Move the 'prev' pointer to current node for next linking
        prev = curr;

        // Step 3: Recurse on the right subtree
        rec(curr->right);
    }

    // Main function to be called with root node of the tree
    Node* bToDLL(Node* root) {
        head = NULL;   // Reset head and prev before starting
        prev = NULL;
        rec(root);     // Start inorder traversal and link nodes
        return head;   // Return the head of the final doubly linked list
    }
};





      //        code by  love babbar 
// using inorder LNR
class Solution {
public:
    void solve(Node* root, Node*&head,Node*&tail){
        if(root==NULL) return;
        // L
        solve(root->left,head,tail);
        // assume that left mai LL bangyi hai
        // update head and tail, connect root node to left LL
        // N
        if(tail!=NULL){
            tail->right = root;
            root->left = tail;
            // tail update
            tail = root;
        }
        else{
            head = root;
            tail = root;
        }
        // R
        solve(root->right,head,tail);
    }
    Node* bToDLL(Node* root) {
        Node* head = NULL;
        Node* tail = NULL;
        solve(root,head,tail);
        return head;
    }
};






// Using RNL
class Solution {
public:
    void solve(Node* root, Node*&head){
        if(root==NULL) return;
        // RNL
        // R
        solve(root->right,head);
        // assume that right part ki LL bangyi hogi and head right par ki LL ki start node par hoga
        // N
        root->right = head;
        if(head!=NULL){
            head->left = root;
        }
        // N and R ki LL ban chuki hai
        // update head, root node pe lagado
        head = root;
        // left part pending now
        // L
        solve(root->left,head);
    }
    Node* bToDLL(Node* root) {
        Node* head = NULL;
        solve(root,head);
        return head;
    }
};
