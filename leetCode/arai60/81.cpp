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
        return buildBFS(nums,0,nums.size()-1);
    }

    TreeNode* buildBFS(vector<int>& nums, int start, int end){
        if(start>end)return nullptr;
        int center = (start+end)/2;
        TreeNode* ans = new TreeNode(nums[center]);
        ans->right = buildBFS(nums,center+1,end);
        ans->left = buildBFS(nums,start,center-1);
        return ans;
    }
};