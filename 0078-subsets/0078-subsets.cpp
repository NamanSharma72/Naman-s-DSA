class Solution {
public:
    void doit(int idx , vector<int>& nums , vector<int> &use , vector<vector<int>> &ans){
        if(idx >= nums.size()){
            ans.push_back(use);
            return;
        }
        use.push_back(nums[idx]);
        doit(idx+1 , nums , use , ans);
        use.pop_back();
        doit(idx+1 , nums , use , ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> use;
        vector<vector<int>> ans;
        doit(0 , nums , use , ans);
        return ans;
    }
};