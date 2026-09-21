class Solution {
public:
    long long maxValue(vector<int>& nums) {
        for(int i = 0 ; i<nums.size() ; i++) if(i%2 != 0) nums[i] = -nums[i];
        long long originalPulse = 0;
        for(int i = 0 ; i<nums.size() ; i++) originalPulse+=nums[i];
        if(nums.size() < 2) return originalPulse;
        vector<int> evenPairs;
        for(int i = 0 ; i<nums.size()-1 ; i+=2) evenPairs.push_back(nums[i]+nums[i+1]);
        vector<int> oddPairs;
        for(int i = 1 ; i<nums.size()-1 ; i+=2) oddPairs.push_back(nums[i]+nums[i+1]);
        long long evenMin = LLONG_MAX , evenSum = 0;
        for(int i = 0 ; i<evenPairs.size() ; i++){
            evenSum = min(evenSum + evenPairs[i] , (long long)evenPairs[i]);
            evenMin = min(evenMin , evenSum);
        }
        long long oddMin = LLONG_MAX , oddSum = 0;
        for(int i = 0 ; i<oddPairs.size() ; i++){
            oddSum = min(oddSum + oddPairs[i] , (long long)oddPairs[i]);
            oddMin = min(oddMin , oddSum);
        }
        long long bestGain = max((long long)0 , -2 * min(evenMin , oddMin));
        originalPulse+=bestGain;
        return originalPulse; 
    }
};