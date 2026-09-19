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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return solve(root, p, q);
    }

    TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q) {

        if(node == NULL) return NULL;

        if(node->val < p->val && node->val < q->val) return solve(node->right, p, q);
        if(node->val > p->val && node->val > q->val) return solve(node->left, p, q);

        return node;
    }
};
