class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> freq(2001 , 0);
        for(int i = 0 ; i<arr.size() ; i++){
            freq[arr[i]]++;
        }
        int count = 0;
        for(int i = 1 ; i<freq.size() ; i++){
            if(freq[i] == 0) count++;
            if(count == k) return i;
        }
        return -1;
    }
};