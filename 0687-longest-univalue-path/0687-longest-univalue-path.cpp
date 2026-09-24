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
    int maxi = INT_MIN;
    int doit(TreeNode* node){
        if(node == NULL) return 0;
        int left = doit(node->left);
        int right = doit(node->right);
        int currPath = 0;
        if(node->left != NULL && node->left->val == node->val) currPath+=left;
        if(node->right != NULL && node->right->val == node->val) currPath+=right;
        maxi = max(maxi , currPath);
        int toReturn = 1;
        if((node->left != NULL && node->left->val == node->val) && (node->right != NULL && node->right->val == node->val)){
            toReturn+=max(left , right);
        }
        else if(node->left != NULL && node->left->val == node->val){
            toReturn+=left;
        }
        else if(node->right != NULL && node->right->val == node->val){
            toReturn+=right;
        }
        return toReturn;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        doit(root);
        return maxi;
    }
};