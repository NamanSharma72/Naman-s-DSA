class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int count = 0;
        vector<int> modK(nums.size());
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]%modulo == k) count++;
            modK[i] = count;
            if(mpp.find(count) == mpp.end()) mpp[count] = i;
        }
        for(int i = 0 ; i<nums.size() ; i++) cout << modK[i] << " ";
        long long finalAns = 0;
        unordered_map<int , int> mpp1;
        int count1 = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(modK[i]%modulo == k) finalAns++;
            // else{
                int left = (modK[i]-k)%modulo;
                if(mpp1.find(left) != mpp1.end()) finalAns+=mpp1[left];
            // }
            if(nums[i]%modulo == k) count1++;
            mpp1[count1%modulo]++;
        }
        return finalAns;
    }
};