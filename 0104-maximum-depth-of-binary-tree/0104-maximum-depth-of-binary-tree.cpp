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
    int doit(TreeNode* Node){
        if(Node == NULL) return 0;
        return 1 + max(doit(Node->left) , doit(Node->right));
    }
    int maxDepth(TreeNode* root) {
        return doit(root);
    }
};