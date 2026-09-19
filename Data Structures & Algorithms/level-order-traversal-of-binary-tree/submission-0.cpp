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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL) return {};
        vector<vector<int>> res;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while(!q.empty()){
            TreeNode* node = q.front().first; int val = q.front().second; q.pop();
            if(res.size() < val) {
                res.push_back({});
            }
            res[val-1].push_back(node->val);

            if(node->left != NULL) q.push({node->left, val+1});
            if(node->right != NULL) q.push({node->right, val+1});
        }

        return res;
    }
};
