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
        return DFS(nums,0,nums.size()-1);
    }
    TreeNode* DFS(vector<int>& nums,int start, int end){
        int mid = (start+end)/2;
        if(start>end)return nullptr;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = DFS(nums,start,mid-1);
        node->right = DFS(nums,mid+1,end);
        return node;
    }
};