/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

Here we have 4 possible cases:
if(root== NULL) means we didn’t find the element in the tree, so we’ll return null.
if(root->val == val) we find our root, simply return it.
if(root->val > val) as our current value is greater & in BST lift side we’ll have smaller values, so we’ll search for the left tree only.
if(root->val < val) here current value is less so we’ll simply search on the right tree.
Time complexity: O(n), worst case it can have 1node in every stage!
 */
 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root== NULL) return NULL;
        if(root->val == val) return root;
        if(root->val > val) return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};