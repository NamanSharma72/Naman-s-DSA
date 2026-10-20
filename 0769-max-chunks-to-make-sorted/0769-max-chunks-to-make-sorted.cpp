class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum = 0;
        int count = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            sum+=arr[i];
            int original = (i * (i+1))/2;
            if(original == sum) count++;
        }
        return count;
    }
};