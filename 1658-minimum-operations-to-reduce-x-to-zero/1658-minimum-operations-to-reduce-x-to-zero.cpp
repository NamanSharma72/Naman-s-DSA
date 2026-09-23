class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxSubSize = INT_MIN;
        int l = 0 ,  r = 0;
        int totalSum = accumulate(nums.begin() , nums.end() , 0);
        if(x > totalSum) return -1;
        int find = totalSum - x;
        int sum = 0;
        while(r < nums.size()){
            sum+=nums[r];
            while(sum > find){
                sum-=nums[l];
                l++;
            }
            if(sum == find) maxSubSize = max(maxSubSize , r-l+1);
            r++;
        }
        if(maxSubSize == INT_MIN) return -1;
        return nums.size() - maxSubSize;
    }
};