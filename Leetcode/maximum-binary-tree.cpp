/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    void makeTree(TreeNode* root, int s, int e, vector<int>& nums) {
        int mx = INT_MIN, mxidx = -1;
        for (int i = s; i <= e; i++) {
            mx = max(mx, nums[i]);
            if (mx == nums[i]) mxidx = i;
        }

        if (s != mxidx) {
            TreeNode* l = new TreeNode();
            makeTree(l, s, mxidx - 1, nums);
            root->left = l;
        }

        if (e != mxidx) {
            TreeNode* r = new TreeNode();
            makeTree(r, mxidx + 1, e, nums);
            root->right = r;
        }
        root->val = nums[mxidx];
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        makeTree(root, 0, nums.size() - 1, nums);
        return root;
    }
};