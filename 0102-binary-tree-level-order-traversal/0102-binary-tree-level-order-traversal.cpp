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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        vector<int> use;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            for(int i = 0 ; i<size ; i++){
                TreeNode* Node = qt.front();
                qt.pop();
                use.push_back(Node->val);
                if(Node->left != NULL) qt.push(Node->left);
                if(Node->right != NULL) qt.push(Node->right);
            }
            ans.push_back(use);
            use.clear();
        }
        return ans;
    }
};