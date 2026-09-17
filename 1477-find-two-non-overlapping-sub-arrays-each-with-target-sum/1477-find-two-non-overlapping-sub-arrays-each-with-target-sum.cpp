class Solution {
public:
    int dp[100000][3];
    int doit(int idx , vector<pair<int,int>> &vt , int k){
        if(k == 2) return 0;
        if(idx == vt.size()) return 1e9;
        if(dp[idx][k] != -1) return dp[idx][k];
        int skip = doit(idx +1 , vt , k);
        int low = idx+1 , high = vt.size()-1 , index = vt.size();
        while(low <= high){
            int mid = low + ((high-low)/2);
            if(vt[mid].first > vt[idx].second){
                index = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        int take = (vt[idx].second - vt[idx].first + 1) + doit(index , vt , k+1);
        return dp[idx][k] = min(skip , take);
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int , int> mpp;
        vector<pair<int,int>> vt;
        int sum = 0;
        mpp[sum] = -1;
        for(int i = 0 ; i<arr.size() ; i++){
            sum+=arr[i];
            int left = sum - target;
            if(mpp.find(left) != mpp.end()) vt.push_back({mpp[left]+1 , i});
            mpp[sum] = i;
        }
        if(vt.size() <= 1) return -1;
        memset(dp , -1 , sizeof(dp));
        int ans = doit(0 , vt , 0);
        if(ans == 1e9) return -1;
        return ans;
    }
};