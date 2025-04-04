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
public:
    bool isValidBST(TreeNode* root) {
        return DFS(root,LONG_MIN,LONG_MAX);
    }
    bool DFS(TreeNode* root,long minVal,long maxVal){
        if(!root)return true;
        if(root->val <= minVal || maxVal <= root->val)return false;
        return (DFS(root->left,minVal,root->val)&&DFS(root->right,root->val,maxVal));
    }
};