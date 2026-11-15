class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long maxi = LLONG_MIN;
        vector<long long> mpp(k , LLONG_MAX);
        long long sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            sum+=nums[i];
            int lenRem = (i+1)%k;
            if(lenRem == 0) maxi = max(maxi , sum);
            if(mpp[lenRem] != LLONG_MAX){
                maxi = max(maxi , sum-mpp[lenRem]);
                if(sum < mpp[lenRem]) mpp[lenRem] = sum;
            }
            else mpp[lenRem] = sum;
        }
        return maxi;
    }
};