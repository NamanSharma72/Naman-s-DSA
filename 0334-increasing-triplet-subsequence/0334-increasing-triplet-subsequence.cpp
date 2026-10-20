class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> minLeft(nums.size() , -1);
        int mini = INT_MAX;
        for(int i = 0 ; i<nums.size() ; i++){
            minLeft[i] = mini;
            mini = min(mini , nums[i]);
        }
        int maxi = INT_MIN;
        vector<int> maxRight(nums.size() , -1);
        for(int i = nums.size()-1 ; i>=0 ; i--){
            maxRight[i] = maxi;
            maxi = max(maxi , nums[i]);
        }
        // for(int i = 0 ; i<nums.size() ; i++) cout << maxRight[i] << " ";
        for(int i = 1 ; i<nums.size()-1 ; i++){
            if(minLeft[i] < nums[i] && maxRight[i] > nums[i]) return true;
        }
        return false;
    }
};