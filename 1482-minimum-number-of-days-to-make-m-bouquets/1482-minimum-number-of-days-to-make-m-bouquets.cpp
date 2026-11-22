class Solution {
public:
    bool possible(vector<int>& bloomDay , int day , int m , int k){
        int groups = 0 , count = 0;
        for(int i = 0 ; i<bloomDay.size() ; i++){
            if(day >= bloomDay[i]) count++;
            else count = 0;
            if(count == k){
                groups++;
                count = 0;
            }
        }
        return groups >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = high - ((high-low)/2);
            if(possible(bloomDay , mid ,  m , k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};