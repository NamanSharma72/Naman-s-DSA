class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int , int> mpp;
        mpp[0] = -1;
        int minAns = INT_MAX;
        int sum = 0;
        vector<int> minTillI(arr.size() , 1e9);
        for(int i = 0 ; i<arr.size() ; i++){
            sum+=arr[i];
            if(i > 0) minTillI[i] = minTillI[i-1];
            int left = sum - target;
            if(mpp.find(left) != mpp.end()){
                if(mpp[left] >= 0) minAns = min(minAns , i-mpp[left] + minTillI[mpp[left]]);
                if(i > 0) minTillI[i] = min(minTillI[i-1] , i - mpp[left]);
                else minTillI[i] = 1;
            }
            mpp[sum] = i;
        }
        if(minAns >= 1e9) return -1;
        return minAns;
    }
};