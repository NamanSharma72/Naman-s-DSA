class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k , 0);
        vector<long long> dp(k , 0);
        for(int i = 0 ; i<nums.size() ; i++){
            vector<long long> newDp(k , 0);
            int currEleRem = nums[i]%k;
            newDp[currEleRem]++;
            for(int r = 0 ; r<k ; r++){
                int newRem = (r * currEleRem)%k;
                newDp[newRem]+=dp[r];
            }
            dp = newDp;
            for(int r = 0 ; r<k ; r++) ans[r]+=newDp[r];
        }
        return ans;
    }
};