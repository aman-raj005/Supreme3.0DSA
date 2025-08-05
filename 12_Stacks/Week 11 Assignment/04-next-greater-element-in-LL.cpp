// leetcode 1019. Next Greater Node in Linked List

1019. Next Greater Node In Linked List
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109

//     my code 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // Step 1: Convert linked list to vector
        vector<int> linkedl;  // Stores all values from the linked list
        vector<int> ans;      // To store final answers (next greater nodes)

        // Traverse the linked list and collect all values in a vector
        while (head) {
            linkedl.push_back(head->val);
            head = head->next;
        }

        // Step 2: Use a monotonic stack to find next greater elements
        stack<int> st; // Stack will keep elements in decreasing order

        // Traverse from right to left of the vector
        for (int i = linkedl.size() - 1; i >= 0; i--) {
            int element = linkedl[i];

            // Pop all elements from stack that are less than or equal to current element
            while (!st.empty() && st.top() <= element) {
                st.pop();
            }

            // If stack is empty, no greater element to the right
            if (st.empty()) {
                ans.push_back(0);
            } else {
                // The top of the stack is the next greater element
                ans.push_back(st.top());
            }

            // Push current element to stack
            st.push(element);
        }

        // Since we filled ans in reverse order, reverse it back
        reverse(ans.begin(), ans.end());

        return ans;
    }
};



//              code by lakchya 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        while(head){
            ll.push_back(head->val);
            head = head->next;
        }
        stack<int>st;
        // vector<int> ans(ll.size());   // initialized with 0
        for(int i = 0; i<ll.size();i++){
            while(!st.empty() && ll[i]>ll[st.top()]){
                // means ith element is the next greater of the element index
                int kids = st.top();
                st.pop();
                ll[kids] = ll[i]; 
            }
            st.push(i);
        }
        while(!st.empty()){
            ll[st.top()]= 0; st.pop();
        }
        ll[ll.size()-1] = 0;
        return ll;
    }
};


// alternative approach
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // creating a stack of pairs to hold index-value pairs
        stack<pair<int,int>>st;
        // creating a vector to store the final result
        vector<int>ans;
        int i = 0;
        // iterate through LL until head becomes NULL
        while(head){
            ans.push_back(0);

            while(!st.empty() && st.top().second<head->val){
                auto top = st.top();
                st.pop();
                ans[top.first]=head->val;
            }
            st.push({i++, head->val});
            head=head->next;
        }
        return ans;
    }
};
