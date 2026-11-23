class Solution {
public:
    int dp[100][2];
    int doit(int idx , vector<int>& nums , int canRob){
        if(idx >= nums.size()) return 0;
        if(dp[idx][canRob] != -1) return dp[idx][canRob];
        int take = 0;
        if(idx == 0){
            take = nums[idx] + doit(idx+2 , nums , 0);
        }
        else if(idx ==  nums.size()-1){
            if(canRob == 1) take = nums[idx] + doit(idx+2 , nums , 1);
        }
        else take = nums[idx] + doit(idx+2 , nums , canRob);
        int skip = doit(idx+1 , nums , canRob);
        return dp[idx][canRob] = max(take , skip);
    }
    int rob(vector<int>& nums) {
        // 1 means can rob last house and 0 means cannot rob last house
        memset(dp , -1 , sizeof(dp));
        return doit(0 , nums , 1);
    }
};