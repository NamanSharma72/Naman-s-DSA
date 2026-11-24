class Solution {
public:
    int doit(int weight , vector<int>& weights){
        int count = 0;
        int sum = 0;
        for(int i = 0 ; i<weights.size() ; i++){
            if(sum + weights[i] > weight){
                count++;
                sum = weights[i];
            }
            else sum+=weights[i];
        }
        if(sum > 0) count++;
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end());
        int high = accumulate(weights.begin() , weights.end(),0);
        int ans = -1;
        while(low <= high){
            int mid = high - ((high-low)/2);
            if(doit(mid , weights) <= days){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};