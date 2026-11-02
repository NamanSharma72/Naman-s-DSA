class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(index == 0 && value == 1) return -1;
        if(value%2 == 0){
            int firstElement = value - 1LL*2*index;
            if(firstElement < 2) return -1;
            return value + 1LL*2*(n-1-index);
        }
            // if(value < 2) return -1;
            // check prime by the help of smallest prime factor
        int spf = -1;
        for(int i = 2 ; i*i<=value ; i++){
            if(value%i == 0){
                spf = i;
                break;
            }
        }
        if(index == 0){
            if(spf != -1) return (value + spf) + 1LL*2*(n-2-index);
            return 1LL*2*value + 1LL*2*(n-2-index);
        }
        if(spf == -1) return -1;
        int firstElement = (value - spf) - 1LL*2*(index-1);
        if(firstElement <2) return -1;
        if(n-1 == index) return value;
        return (spf+value) + 1LL*2*(n-2-index);
    }
};