// GFG: Intersection of Two Linked Lists

Intersection of Two Linked Lists
Difficulty: EasyAccuracy: 35.3%Submissions: 67K+Points: 2Average Time: 15m
Given two linked lists head1 and head2, find the intersection of two linked lists. Each of the two linked lists contains distinct node values.

Note: The order of nodes in this list should be the same as the order in which those particular nodes appear
 in input head1 and return null if no common element is present.

Examples:

Input: LinkedList1: 9->6->4->2->3->8 , LinkedList2: 1->2->8->6
 
Output: 6->2->8
Explanation: Nodes 6, 2 and 8 are common in both of the lists and the order will be according to LinkedList1. 
Input: LinkedList1: 5->3->1->13->14 , LinkedList2: 3->13
 
Output: 3->13
Explanation: Nodes 3 and 13 are common in both of the lists and the order will be according to LinkedList1. 
Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)

Constraints:
1 <= no. of nodes in head1, head2 <= 104
1 <= node->data <= 105

Company Tags
VMWareFlipkartAccoliteAmazonMicrosoft24*7 Innovation LabsD-E-ShawWalmartKomli MediaTaxi4Sure
Topic Tags


// my code

#include <unordered_map>

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int, int> mapping;
        Node* dummy = new Node(-1); // Dummy node to simplify insertion
        Node* tail = dummy; // Tail pointer to build the new list

        // Store frequencies of nodes in head2
        while (head2 != NULL) {
            mapping[head2->data]++;
            head2 = head2->next;
        }

        // Traverse head1 and add intersecting nodes
        while (head1 != NULL) {
            if (mapping.find(head1->data) != mapping.end() && mapping[head1->data] > 0) {
                tail->next = new Node(head1->data); // Add to the new list
                tail = tail->next; // Move tail forward
                mapping[head1->data]--; // Decrement count
            }
            head1 = head1->next;
        }

        Node* result = dummy->next;
        delete dummy; // Clean up dummy node
        return result;
    }
};





  //    code by lakchya   





/* structure of list node:
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
*/

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int, int> map;
        Node* curr = head2;
        // Hash L2 items
        while (curr) {
            map[curr->data]++;
            curr = curr->next;
        }

        Node* IL = NULL; // Intersection list head
        Node* it = NULL; // Intersection list iterator
        curr = head1;

        while (curr) {
            if (map.find(curr->data) != map.end() && map[curr->data] > 0) {
                // Node value found in L2 and count is greater than 0
                if (IL == NULL) {
                    IL = new Node(curr->data);
                    it = IL;
                } else {
                    it->next = new Node(curr->data); 
                    it = it->next;
                }
                map[curr->data]--;
            }
            curr = curr->next;
        }
        return IL;
    }
};
