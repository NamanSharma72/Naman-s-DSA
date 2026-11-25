class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val > key) root->left = deleteNode(root->left , key);
        else if(root->val < key) root->right = deleteNode(root->right , key);
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp1 = root->right;
            while(temp1->left != NULL) temp1 = temp1->left;
            root->val = temp1->val;
            root->right = deleteNode(root->right , temp1->val);
        }
        return root;
    }
};