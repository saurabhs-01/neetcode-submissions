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
    int kthSmallest(TreeNode* root, int k) {
        
        int res = -1;
        int val = k;
        solve(root, val, res);

        return res;
    }

    void solve(TreeNode* root, int& k, int& res) {

        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            k--; 
            if(k== 0) res = root->val;
            return;
        }

        solve(root->left, k, res);
        if(k == 0) return;
        k--;
        if(k==0) {
            res = root->val; return;
        }
        solve(root->right,k, res);
        
        
    }
};
