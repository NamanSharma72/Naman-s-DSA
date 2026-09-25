class Solution {
public:
    vector<tuple<int,int,int>> tree;
    void doit(TreeNode* node , int x , int y){
        if(node == NULL) return;
        tree.push_back({y , x , node->val});
        doit(node->left , x+1 , y-1);
        doit(node->right , x+1 , y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        doit(root , 0 , 0);
        sort(tree.begin() , tree.end());
        vector<vector<int>> ans;
        vector<int> use;
        use.push_back(get<2>(tree[0]));
        for(int i = 1 ; i<tree.size() ; i++){
            if(get<0>(tree[i]) == get<0>(tree[i-1])) use.push_back(get<2>(tree[i]));
            else{
                ans.push_back(use);
                use.clear();
                use.push_back(get<2>(tree[i]));
            }
        }
        ans.push_back(use);
        return ans;
    }
};