class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int i = 0;
        while(i < nums.size()){
            unordered_set<int> st;
            int j = i+1;
            while(j < nums.size()){
                int left = -(nums[j] + nums[i]);
                if(st.count(left)) {
                    ans.push_back({nums[i] , nums[j] , left});
                    st.insert(nums[j]);
                    j++;
                    while(j < nums.size() && nums[j] == nums[j-1]) j++;
                }
                else {
                    st.insert(nums[j]);
                    j++;
                }
            }
            i++;
            while(i < nums.size() && nums[i] == nums[i-1]) i++;
        }
        return ans;
    }
};