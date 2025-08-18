// gfg: sort 0s, 1s and 2s in LL
Sort a linked list of 0s, 1s and 2s
Difficulty: MediumAccuracy: 60.75%Submissions: 253K+Points: 4Average Time: 30m
Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 ? 2 ? 2 ? 1 ? 2 ? 0 ? 2 ? 2

Output: 0 ? 1 ? 1 ? 2 ? 2 ? 2 ? 2 ? 2

Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
Input: head = 2 ? 2 ? 0 ? 1

Output: 0 ? 1 ? 2 ? 2

Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be 0 ? 1 ? 2 ? 2.
Constraints:
1 = no. of nodes = 106
0 = node->data = 2


//                       my code 
/* Node is defined as
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

void functiontostore(Node* &currentNode, Node* &NodeHead, Node* &NodeTail) {
    currentNode->next = NULL; // break link to original list
    if (NodeHead == NULL) {
        NodeHead = currentNode;
        NodeTail = currentNode;
    } else {
        NodeTail->next = currentNode;
        NodeTail = currentNode;
    }
}

class Solution {
public:
    Node* segregate(Node* head) {
        Node* zeroNodeHead = NULL;
        Node* zeroNodeTail = NULL;
        
        Node* oneNodeHead = NULL;
        Node* oneNodeTail = NULL;
        
        Node* twoNodeHead = NULL;
        Node* twoNodeTail = NULL;

        Node* temp = head;

        // Step 1: Distribute nodes into 0, 1, 2 lists
        while (temp != NULL) {
            Node* currentNode = temp;
            temp = temp->next; // move temp first to avoid breaking link
            if (currentNode->data == 0) {
                functiontostore(currentNode, zeroNodeHead, zeroNodeTail);
            } else if (currentNode->data == 1) {
                functiontostore(currentNode, oneNodeHead, oneNodeTail);
            } else {
                functiontostore(currentNode, twoNodeHead, twoNodeTail);
            }
        }

        // Step 2: Merge 0s ? 1s ? 2s

        // Connect 0s to 1s
        if (zeroNodeTail != NULL) {
            zeroNodeTail->next = oneNodeHead;
        } else {
            zeroNodeHead = oneNodeHead;
        }

        // Connect 1s to 2s
        if (oneNodeTail != NULL) {
            oneNodeTail->next = twoNodeHead;
        } else if (zeroNodeTail != NULL) {
            zeroNodeTail->next = twoNodeHead;
        }

        // Step 3: Return the new head of the list
        if (zeroNodeHead != NULL) return zeroNodeHead;
        if (oneNodeHead != NULL) return oneNodeHead;
        return twoNodeHead;
    }
};






//            code by lakchyaa 

class Solution
{
    public:
    void insertAtTail(Node* toMove, Node* &head, Node* &tail){
        // LL is empty
        if(head == NULL && tail == NULL){
            head = toMove;
            tail = toMove;
        }
        else{
            tail->next = toMove;
            tail = toMove;
        }
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;

        Node* oneHead = NULL;
        Node* oneTail = NULL;
        
        Node* twoHead = NULL;
        Node* twoTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            // create toMove node
            Node* toMove = temp;
            temp = temp->next;
            // isolate toMove
            toMove->next = NULL;
            if(toMove->data == 0){
                insertAtTail(toMove,zeroHead,zeroTail);
            }
            else if(toMove->data == 1){
                insertAtTail(toMove,oneHead,oneTail);
            }
            else if(toMove->data == 2){
                insertAtTail(toMove,twoHead,twoTail);
            }
        }
        // teeno LL ready hai->merge
        // empty wali possibility bhoolna mat
        if(zeroHead != NULL){
            if(oneHead != NULL){
                zeroTail->next = oneHead;
                // merge with 2 wali list
                oneTail->next = twoHead;
            }
            else{
                // one list is empty
                zeroTail->next = twoHead;
            }
            return zeroHead;
        }
        else{
            // zero list is empty
            if(oneHead != NULL){
                oneTail->next = twoHead;
                return oneHead;
            }
            else{
                return twoHead;
            }
        }

    }
};

