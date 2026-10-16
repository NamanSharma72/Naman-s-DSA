class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0 , mod = 1e9 + 7;
        for(int i = 0 ; i<nums1.size() ; i++) ans+=abs(nums1[i] - nums2[i]);
        vector<int> use1 = nums1;
        sort(use1.begin() , use1.end());
        long long mini = ans;
        for(int i = 0 ; i<nums1.size() ; i++){
            int idx1 = upper_bound(use1.begin() , use1.end() , nums2[i]) - use1.begin();
            if(idx1 < nums1.size()){
                long long u1 = ans - abs(nums2[i] - nums1[i]) + abs(use1[idx1] - nums2[i]);
                mini = min(mini , u1);
            }
            long long u2 = LLONG_MAX;
            if((idx1 - 1) >= 0 && (idx1 -1) < nums1.size()) u2 = ans - abs(nums2[i] - nums1[i]) + abs(use1[idx1-1] - nums2[i]);
            mini = min(mini , u2);
        }
        return mini%mod;
    }
};