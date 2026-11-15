class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int totalSum = 0;
        int oddSum = 0 , evenSum = 0;
        int ans = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            totalSum+=arr[i];
            if(totalSum%2 == 0){
                ans = (ans+oddSum)%mod;
                evenSum++;
            }
            else{
                ans = (ans+evenSum)%mod;
                ans++;
                oddSum++;
            }
        }
        return ans;
    }
};