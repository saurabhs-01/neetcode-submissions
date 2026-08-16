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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == NULL || q == NULL) {
            if(p == NULL && q == NULL) return true;
            return false;
        }

        if(p-> val != q->val) return false;

        bool sameL = false; bool sameR = false;
        if(p->left == NULL || q->left == NULL) {
            if(p->left == NULL && q->left == NULL) sameL = true;
            else return false;
        }
        if(!sameL) sameL = isSameTree(p->left, q->left);

        if(p->right == NULL || q->right == NULL) {
            if(p->right == NULL && q->right == NULL) sameR = true;
            else return false;
        }
        if(!sameR) sameR = isSameTree(p->right, q->right);

        return sameL && sameR;
    }
};
