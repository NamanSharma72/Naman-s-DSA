class Solution {
public:
    int dp[501][501];
    int doit(int idx1 , int idx2 , vector<int>& nums1 , vector<int>& nums2){
        if(idx1 == nums1.size() || idx2 == nums2.size()) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int match = 0 , notMatch = 0;
        if(nums1[idx1] == nums2[idx2]) {
            match = 1 + doit(idx1+1 , idx2+1 , nums1 , nums2);
        }
        else{
            notMatch = max(doit(idx1+1 , idx2 , nums1 , nums2) , doit(idx1 , idx2+1 , nums1 , nums2));
        }

        return dp[idx1][idx2] = max(match , notMatch);

    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , nums1 , nums2);
    }
};