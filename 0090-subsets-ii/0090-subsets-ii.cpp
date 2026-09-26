class Solution {
public:
    vector<vector<int>> ans;
    void doit(int idx , vector<int>& nums , vector<int>& use){
        ans.push_back(use);
        set<int> st;
        for(int i = idx ; i<nums.size() ; i++){
            if(st.count(nums[i])) continue;
            use.push_back(nums[i]);
            st.insert(nums[i]);
            doit(i+1 , nums , use);
            use.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> use;
        sort(nums.begin() , nums.end());
        doit(0 , nums , use);
        return ans;
    }
};