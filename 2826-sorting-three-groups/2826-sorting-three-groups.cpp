class Solution {
public:
    int dp[101][101];
    int doit(int idx , vector<int>& nums , int prev){
        if(idx == nums.size()) return 0;
        if(dp[idx][prev] != -1) return dp[idx][prev];
        int skip = doit(idx+1 , nums , prev);
        int take = 0;
        if(prev == 0 || nums[idx] >= nums[prev-1]){
            take = 1 + doit(idx+1 , nums , idx+1);
        }
        return dp[idx][prev] = max(take , skip);
    }
    int minimumOperations(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        return nums.size() - doit(0 , nums , 0);
    }
};