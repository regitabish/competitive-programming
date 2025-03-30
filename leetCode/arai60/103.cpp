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
        bool hasPathSum(TreeNode* root, int targetSum) {
            return DFS(root,targetSum,0);
        }
        bool DFS(TreeNode* root,const int targetSum,int preSum){
            if(root==nullptr)return false;
            int newSum = preSum + root->val;
            if(root->left==nullptr&&root->right==nullptr&&targetSum==newSum)return true;
            return (DFS(root->left,targetSum,newSum)||DFS(root->right,targetSum,newSum));
        }
    };