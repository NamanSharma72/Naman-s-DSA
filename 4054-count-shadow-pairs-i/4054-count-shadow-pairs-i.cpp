class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int> nextSmaller(nums.size());
        stack<int> st;
        unordered_map<int , vector<int>> mpp;
        for(int i = 0 ; i<nums.size() ; i++) mpp[nums[i]].push_back(i);
        long long count = 0;
        for(int i = nums.size()-1 ; i>=0 ; i--){
            while(!st.empty() && (nums[i] <= nums[st.top()])) st.pop();
            if(st.empty()) nextSmaller[i] = nums.size();
            else nextSmaller[i] = st.top();
            st.push(i);
            int ans = nextSmaller[i] - i - 1;
            int left = upper_bound(mpp[nums[i]].begin() , mpp[nums[i]].end() , i) - mpp[nums[i]].begin();
            int right = lower_bound(mpp[nums[i]].begin() , mpp[nums[i]].end() , nextSmaller[i]) - mpp[nums[i]].begin();
            ans = ans - (right - left);
            count+=ans;
        }
        return count;
    }
};