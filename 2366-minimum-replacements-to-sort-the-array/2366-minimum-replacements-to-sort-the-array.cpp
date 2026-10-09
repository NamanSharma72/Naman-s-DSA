class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int mini = nums[n-1];
        for(int i = n-2 ; i>=0 ;  i--){
            if(nums[i] > mini){
                int parts = nums[i]/mini;
                if(nums[i]%mini != 0) parts++;
                ans+=(parts-1);
                int smallestPart = nums[i]/parts;
                mini = min(mini , smallestPart);
            }
            mini = min(mini , nums[i]);
        }
        return ans;
    }
};