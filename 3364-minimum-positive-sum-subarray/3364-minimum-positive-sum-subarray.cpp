class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        for(int i = l ; i<= r ; i++){
            int left = 0 , right = 0 , sum = 0;
            while(right < nums.size()){
                sum+=nums[right];
                if(right-left+1 > i){
                    sum-=nums[left];
                    left++;
                }
                if(right-left+1 == i && sum > 0) mini = min(mini , sum);
                right++;
            }
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};