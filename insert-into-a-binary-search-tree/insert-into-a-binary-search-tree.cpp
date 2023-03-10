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
 */

 /*
 If the root is empty, the new tree node can be returned as the root node.

Otherwise compare root. val is related to the size of the new value:

If root->val is > than the target value, indicating that the target value should be inserted into the left subtree of the root.For thet we have to reach to the leftmost node of the left subtree.

If root->val is < the target value, indicating that the new value should be inserted into the right subtree of the root.For thet we have to reach to the rightmost node of the right subtree.
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* temp=root;
        while(true){
            if(val<=temp->val){
                if(temp->left!=NULL){
                    temp=temp->left;
                }
                else{
                    temp->left=new TreeNode(val);
                    break;
                }
            }
            else{
                if(temp->right!=NULL){
                    temp=temp->right;
                }
                else{
                    temp->right=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};