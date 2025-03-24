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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildDFS(nums,0,nums.size()-1);
    }
    TreeNode* buildDFS(vector<int>& nums,int start,int end){
        if(start>end)return nullptr;
        int mid = (start+end)/2;
        int midVal = nums[mid];
        TreeNode* tree = new TreeNode(midVal);
        tree->left = buildDFS(nums,start,mid-1);
        tree->right = buildDFS(nums,mid+1,end);
        return tree;
    }
};