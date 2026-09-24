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
    void doit(TreeNode* Node){
        if(Node == NULL) return;
        doit(Node->left);
        doit(Node->right);
        ans.push_back(Node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        doit(root);
        return ans;
    }
};