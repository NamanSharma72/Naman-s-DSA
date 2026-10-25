class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int l = 0 , r = 0;
        int count0 = 0;
        while(r < nums.size()){
            if(nums[r] == 0) count0++;
            while(count0-k > 0){
                if(nums[l] == 0) count0--;
                l++;
            }
            maxi = max(maxi , r-l+1);
            r++;
        }
        return maxi;
    }
};