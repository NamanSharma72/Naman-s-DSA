class Solution {
public:
    vector<vector<int>> ans;
    void doit(int idx , vector<int>& nums , vector<int> &use , int prev){
        if(use.size() >= 2) ans.push_back(use);
        set<int> used;
        for(int i = idx ; i<nums.size() ; i++){
            if((used.count(nums[i]) != 0) || (nums[i] < prev)) continue;
            use.push_back(nums[i]);
            used.insert(nums[i]);
            doit(i+1 , nums , use , nums[i]);
            use.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> use;
        doit(0 , nums , use , -1000);
        return ans;
    }
};