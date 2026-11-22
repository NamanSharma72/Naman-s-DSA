class Solution {
public:
    int time(int speed , vector<int>& piles){
        int t = 0;
        for(int i = 0 ; i<piles.size() ; i++){
            t+=(piles[i]/speed);
            if(piles[i]%speed > 0) t++;
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin() , piles.end());
        while(low <= high){
            int mid = high - ((high-low)/2);
            if(time(mid , piles) <= h) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};