class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long finalAns = 0;
        unordered_map<int , int> mpp1;
        int count1 = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]%modulo == k) count1++;
            if(count1%modulo == k) finalAns++;
            int left = (count1-k)%modulo;
            if(mpp1.find(left) != mpp1.end()) finalAns+=mpp1[left];
            mpp1[count1%modulo]++;
        }
        return finalAns;
    }
};