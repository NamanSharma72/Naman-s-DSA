class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = INT_MIN;
        int sum = 0;
        unordered_map<int , int> mpp;
        mpp[0] = -1;
        int total = accumulate(nums.begin() , nums.end() , 0);
        if(x == total) return nums.size();
        int findSum = total-x;
        for(int i = 0 ; i<nums.size() ; i++){
            sum+=nums[i];
            int left = sum - findSum;
            if(mpp.find(left) != mpp.end()){
                ans = max(ans , i - mpp[left]);
            }
            mpp[sum] = i;
        }
        if(ans == INT_MIN) return -1;
        return nums.size() - ans;
    }
};