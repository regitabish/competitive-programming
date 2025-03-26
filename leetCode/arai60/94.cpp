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
            return DFS(root,LONG_MAX,LONG_MIN);
        }
        bool DFS(TreeNode* root, long maxVal, long minVal){
            if(!root)return true;
            if(root->val >= maxVal || root->val <= minVal)return false;
            return (DFS(root->left,root->val,minVal)&&DFS(root->right,maxVal,root->val));
        }
    };