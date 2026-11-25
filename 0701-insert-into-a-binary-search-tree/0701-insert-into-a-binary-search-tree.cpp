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
    TreeNode* doit(TreeNode* node , int val){
        if(node == NULL) return new TreeNode(val);
        if(node->val < val) node->right = doit(node->right , val);
        else node->left = doit(node->left , val);
        return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return doit(root , val);
    }
};