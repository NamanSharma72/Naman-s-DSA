class Solution {
public:
    int maxNonOverlapping(vector<int>& arr, int target) {
        unordered_map<int , int> mpp;
        mpp[0] = -1;
        int mini = INT_MAX;
        int prevEnd = -1;
        int count = 0;
        int sum = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            sum+=arr[i];
            int left = sum - target;
            if((mpp.find(left) != mpp.end()) && mpp[left]+1 > prevEnd){
                count++;
                prevEnd = i;
            }
            mpp[sum] = i;
        }
        return count;
    }
};