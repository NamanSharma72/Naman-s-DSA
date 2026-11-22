class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int low = 1 , high = x/2 , ans = -1;
        while(low <= high){
            int mid = high - ((high-low)/2);
            if(1LL*mid*mid == x) return mid;
            else if(1LL*mid*mid <= x){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
        return 0;
    }
};