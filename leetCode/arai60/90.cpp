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
        return buildDFS(root,targetSum,0);
    }
    bool buildDFS(TreeNode* root, const int targetSum, const int sum){
        if(root==nullptr)return false;
        int newSum = root->val + sum;
        if(root->left==nullptr && root->right==nullptr && newSum == targetSum)return true;
        if(root->left==nullptr && root->right==nullptr && newSum != targetSum)return false;

        return (buildDFS(root->left,targetSum,newSum) || buildDFS(root->right,targetSum,newSum));
        
    }
};