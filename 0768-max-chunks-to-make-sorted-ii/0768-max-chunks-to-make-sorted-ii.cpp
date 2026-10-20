class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> use = arr;
        long long sum = 0;
        sort(use.begin() , use.end());
        long long originalsum = 0;
        int maxi = 0;
        int count = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            sum+=use[i];
            originalsum+=arr[i];
            maxi = max(maxi , arr[i]);
            if(originalsum == sum) count++;
        }
        return count;
    }
};