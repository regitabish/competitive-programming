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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        unordered_map<int,int> inMap;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            inMap[inorder[i]] = i;
        }
        return build(preorder,inMap,preIndex,0,n-1);
    }
    TreeNode* build(vector<int>& preorder,unordered_map<int,int>& inMap,int& preIndex, int left, int right){
        if(right<left)return nullptr;
        int rootVal = preorder[preIndex++];
        TreeNode* node = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];

        node->left = build(preorder,inMap,preIndex,left,inIndex-1);
        node->right = build(preorder,inMap,preIndex,inIndex+1,right);
        return node;
    }
};