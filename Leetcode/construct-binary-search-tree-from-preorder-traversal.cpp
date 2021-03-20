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
    void insert(TreeNode* root, int x) {
        if (root->val == 0) {
            root->val = x;
            return;
        }

        TreeNode* cur = root;

        while (true) {
            if (x > cur->val) {
                if (cur->right != nullptr) {
                    cur = cur->right;
                } else {
                    TreeNode* l = new TreeNode(x);
                    cur->right = l;
                    return;
                }
            } else {
                if (cur->left != nullptr) {
                    cur = cur->left;
                } else {
                    TreeNode* l = new TreeNode(x);
                    cur->left = l;
                    return;
                }
            }
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode();

        for (int i = 0; i < preorder.size(); i++) {
            insert(root, preorder[i]);
        }

        return root;
    }
};