// leetcode 236. Lowest Common Ancestor of a Binary Tree

//      code by sradha khapra                 https://youtu.be/oX5D0uKOMck?feature=shared


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case 1: If the current node is NULL, return NULL
        if(root == NULL) {
            return NULL;
        }

        // Base Case 2: If the current node matches either p or q, return the current node
        // Because if we find either p or q, we return it upwards in the recursion
        if(root->val == p->val || root->val == q->val) {
            return root;
        }

        // Recursive call to the left and right subtree to find p and q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-null, it means p and q are found in different subtrees
        // Hence, the current node is their lowest common ancestor
        if(left && right) {
            return root;
        }

        // If only one side is non-null, return that side (the side where either p or q is found)
        if(left != NULL) {
            return left;
        } else {
            return right;
        }
    }
};



    //          code by love babbar 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL) return NULL;
        // if(root->val == p->val) return p; //value based comparison, in this question all values are unique but if all values are non-unique then used address based comparison
        if(root == p) return p; //address based comparison
        // if(root-> val == q->val) return q;
        if(root == q) return q;

        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL) return NULL;
        else if(leftAns == NULL && rightAns != NULL) return rightAns;
        else if(leftAns != NULL && rightAns == NULL) return leftAns;
        else{
            // both leftAns and rightAns are non null
            return root;
        }
    }
};
