class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int mod = 1e9+7;
        vector<int> freq(31 , 0);
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j = 0 ; j<=31 ; j++){
                if(nums[i] & (1 << j)) freq[j]++;
            }
        }
        long long ans = 0;
        for(int i = 0 ; i<k ; i++){
            long long num = 0;
            for(int j = 0 ; j<31 ; j++){
                if(freq[j] > 0){
                    num |= (1LL << j);
                    freq[j]--;
                }
            }
            ans = (ans + (1LL * num*num)%mod)%mod;
        }
        return ans;
    }
};