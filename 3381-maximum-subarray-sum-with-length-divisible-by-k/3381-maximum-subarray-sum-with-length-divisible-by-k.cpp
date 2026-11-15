class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // for all the remainders store the minimum sum subarray
        long long maxi = LLONG_MIN;
        unordered_map<int , long long> mpp;
        long long sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            sum+=nums[i];
            if((i+1)%k == 0) maxi = max(maxi , sum);
            int lenRem = (i+1)%k;
            if(mpp.find(lenRem) != mpp.end()){
                maxi = max(maxi , sum-mpp[lenRem]);
                if(sum < mpp[lenRem]) mpp[lenRem] = sum;
            }
            else{
                mpp[lenRem] = sum;
            }
        }
        return maxi;
    }
};