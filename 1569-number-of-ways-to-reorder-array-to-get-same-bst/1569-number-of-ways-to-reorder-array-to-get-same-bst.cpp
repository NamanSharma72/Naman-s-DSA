class Solution {
public:
    int mod = 1e9+7;
    long long combi[1001][1001];
    int doit(vector<int> &nums){
        if(nums.size() <= 1) return 1;
        vector<int> bigger , smaller;
        for(int i = 1 ; i<nums.size() ; i++){
            if(nums[i] > nums[0]) bigger.push_back(nums[i]);
            else smaller.push_back(nums[i]);
        }
        int n = nums.size()-1 , r = smaller.size();
        long long ans = combi[n][r];
        ans = (ans * doit(bigger))%mod;
        ans = (ans * doit(smaller))%mod;
        return ans;
    }
    int numOfWays(vector<int>& nums) {
        for(int i = 0 ; i<=1000 ; i++){
            combi[i][0] = combi[i][i] = 1;
            for(int j = 1 ; j<=i ; j++){
                combi[i][j] = (combi[i-1][j-1] + combi[i-1][j])%mod;
            }
        }
        return (doit(nums)-1 + mod)%mod;
    }
};