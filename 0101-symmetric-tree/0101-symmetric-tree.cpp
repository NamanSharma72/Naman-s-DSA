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
    bool doit(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        return doit(p->left , q->right) && doit(p->right , q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return doit(root->left , root->right);
    }
};