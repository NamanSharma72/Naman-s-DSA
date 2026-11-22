class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX , l = 0 , r = nums.size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            mini = min(mini , nums[mid]);
            if(nums[mid] <= nums[nums.size()-1]) r = mid-1;
            else l = mid+1;
        }
        return mini;
    }
};