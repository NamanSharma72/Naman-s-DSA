class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 1;
        for(int i = 0 ; i<nums1.size() ; i++){
            ans+=abs(nums1[i] - nums2[i]);
        }
        int mini = INT_MAX;
        for(int i = 0 ; i<nums1.size() ; i++){
            if(abs(nums2[i] - nums2[nums2.size()-1]) > abs(nums1[i] - nums2[nums2.size()-1])){
                int use = abs(nums1[i] - nums2[nums2.size()-1]);
                mini = min(mini , use);
            }
            else{
                int use = abs(nums2[i] - nums2[nums2.size()-1]);
                mini = min(mini , use);
            }

            if((nums2[i] > nums2[nums2.size()-1] && nums2[nums2.size()-1] > nums1[i]) || (nums2[i] < nums2[nums2.size()-1] && nums2[nums2.size()-1] < nums1[i])){
                mini = 0;
            }
        }
        return ans + mini;
    }
};