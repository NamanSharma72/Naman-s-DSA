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
    vector<int> ans;
    void doit(TreeNode* node){
        if(node == NULL) return;
        ans.push_back(node->val);
        doit(node->left);
        doit(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        doit(root);
        return ans;
    }
};