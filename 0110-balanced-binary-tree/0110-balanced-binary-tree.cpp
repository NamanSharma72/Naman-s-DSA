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
    int doit(TreeNode* Node , int &flag){
        if(Node == NULL) return 0;
        if(flag == 1) return 1e9;
        int left = doit(Node->left , flag);
        int right = doit(Node->right , flag);
        if(abs(right - left) > 1) flag = 1;
        return 1 + max(right , left);
    }
    bool isBalanced(TreeNode* root) {
        int flag = 0;
        int ans = doit(root , flag);
        return flag == 1 || ans >= 1e9 ? false : true;
    }
};