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
    bool doit(TreeNode* node1 , TreeNode* node2){
        if(node1 == NULL && node2 == NULL) return true;
        if(node1 == NULL || node2 == NULL) return false;
        if(node1->val != node2->val) return false;
        bool left = doit(node1->left , node2->left);
        bool right = doit(node1->right , node2->right);
        return left && right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return doit(p , q);
    }
};