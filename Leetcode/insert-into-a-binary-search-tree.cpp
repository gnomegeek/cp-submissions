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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;

        if (root == nullptr) {
            TreeNode* l = new TreeNode(val);
            return l;
        }

        while (true) {
            if (val < cur->val) {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    TreeNode* l = new TreeNode(val);
                    cur->left = l;
                    return root;
                }
            } else {
                if (cur->right)
                    cur = cur->right;
                else {
                    TreeNode* l = new TreeNode(val);
                    cur->right = l;
                    return root;
                }
            }
        }
        return root;
    }
};