class Solution {
public:
    set<vector<int>> ans;
    void doit(int idx , vector<int>& nums , vector<int> &use , int prev){
        if(idx == nums.size()){
            if(use.size() >= 2) ans.insert(use);
            return;
        }
        doit(idx+1 , nums , use , prev);
        if(nums[idx] >= prev){
            use.push_back(nums[idx]);
            doit(idx+1 , nums , use , nums[idx]);
            use.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> use;
        doit(0 , nums , use , -1000);
        vector<vector<int>> finalAns;
        for(auto &it : ans){
            finalAns.push_back(it);
        }
        return finalAns;
    }
};