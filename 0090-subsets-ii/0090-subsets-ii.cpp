class Solution {
public:
    void doit(int idx , vector<int>& nums , vector<int> &use ,vector<vector<int>> &ans){
        ans.push_back(use);
        unordered_set<int> st;
        for(int i = idx ; i<nums.size() ; i++){
            if(st.count(nums[i])) continue;
            use.push_back(nums[i]);
            st.insert(nums[i]);
            doit(i+1 , nums , use , ans);
            use.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> use;
        vector<vector<int>> ans;
        doit(0 , nums , use , ans);
        return ans;
    }
};