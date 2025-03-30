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
            return build(root,LLONG_MIN,LLONG_MAX);
        }
        bool build(TreeNode* root,long long left,long long right){
            if(root==nullptr)return true;
            int rootVal = root->val;
            if(right<=rootVal || rootVal<=left)return false;
            return (build(root->left,left,rootVal)&&build(root->right,rootVal,right));
        }
    };