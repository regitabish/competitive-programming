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
            return (buildDFS(root,0,targetSum));
        }
    
    private:
        bool buildDFS(TreeNode* root, int sum,const int targetSum){
            if(root==nullptr)return false;
            int newSum = sum + root->val;
            
            if(root->left==nullptr&&root->right==nullptr&&newSum == targetSum)return true;
    
            return (buildDFS(root->left,newSum,targetSum)||buildDFS(root->right,newSum,targetSum));
        }
    };