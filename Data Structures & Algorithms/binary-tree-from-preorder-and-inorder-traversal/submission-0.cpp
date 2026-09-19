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
private:
int index = 0;    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        unordered_map<int, int> mpp; // index map
        for(int i=0;i<n;i++) {
            mpp[inorder[i]] = i;
        }

        return solve(0, n-1, 0, preorder, inorder, mpp);
    }

    TreeNode* solve(int start, int end, int index, vector<int>& preorder, vector<int>& inorder,unordered_map<int, int>& mpp) {

        if(start > end || index >= preorder.size()) return NULL;

        TreeNode* node = new TreeNode(preorder[index]);
        int inorderIndex = mpp[preorder[index]];
        int valuesOnLeft = inorderIndex - start;
        node->left = solve(start, inorderIndex-1, index+1, preorder, inorder, mpp);
        node->right = solve(inorderIndex+1, end, index+ valuesOnLeft+1, preorder, inorder, mpp);

        return node;
    }
};
