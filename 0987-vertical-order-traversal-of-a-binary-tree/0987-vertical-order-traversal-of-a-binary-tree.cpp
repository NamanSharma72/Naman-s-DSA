class Solution {
public:
    vector<tuple<int,int,int>> tree;
    static bool cmp(const tuple<int , int , int> &a , const tuple<int , int , int> &b){
        const auto [val1 , x1 , y1] = a;
        const auto [val2 , x2 , y2] = b;
        if(x1 == x2 && y1 == y2) return val1 < val2;
        if(y1 == y2) return x1 < x2;
        return y1 < y2;
    }
    void doit(TreeNode* node , int x , int y){
        if(node == NULL) return;
        tree.push_back({node->val , x , y});
        doit(node->left , x+1 , y-1);
        doit(node->right , x+1 , y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        doit(root , 0 , 0);
        sort(tree.begin() , tree.end() , cmp);
        // for(auto &[val , x , y] : tree) cout << val << " " << x << " " << y << endl;
        vector<vector<int>> ans;
        vector<int> use;
        use.push_back(get<0>(tree[0]));
        for(int i = 1 ; i<tree.size() ; i++){
            if(get<2>(tree[i]) == get<2>(tree[i-1])) use.push_back(get<0>(tree[i]));
            else{
                ans.push_back(use);
                use.clear();
                use.push_back(get<0>(tree[i]));
            }
        }
        ans.push_back(use);
        return ans;
    }
};