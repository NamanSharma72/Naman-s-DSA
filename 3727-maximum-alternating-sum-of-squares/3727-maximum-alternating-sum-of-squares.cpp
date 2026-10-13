class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0 ; i<nums.size() ; i++) nums[i] = nums[i] * nums[i];
        sort(nums.begin() , nums.end());
        int count = nums.size()/2;
        long long sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i < count) sum = sum - nums[i];
            else sum = sum + nums[i];
        }
        return sum;
    }
};