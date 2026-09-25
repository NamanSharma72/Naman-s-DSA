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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        int flag = 0;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int n = qt.size();
            int index = flag == 0 ? 0 : n-1;
            vector<int> use(n);
            for(int i = 0 ; i<n ; i++){
                TreeNode* Node = qt.front();
                qt.pop();
                use[index] = Node->val;
                index = flag == 0 ? index+1 : index-1;
                if(Node->left != NULL) qt.push(Node->left);
                if(Node->right != NULL) qt.push(Node->right);
            }
            ans.push_back(use);
            flag = !flag;
        }
        return ans;
    }
};