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
class Solution {
private:
    void closestValueHelper(TreeNode* root, double target, double& diff, int& value)
    {
        if(root==NULL)
            return;
            
        if(fabs(root->val-target) < diff)
        {
            diff = fabs(root->val-target);
            value = root->val;
        }
        closestValueHelper(root->left, target, diff, value);
        closestValueHelper(root->right, target, diff, value);
    }
    
public:
    int closestValue(TreeNode* root, double target) {
        double diff = 2.0*INT_MAX;
        int value = INT_MAX;
        closestValueHelper(root, target, diff, value);
        return value;
    }
};