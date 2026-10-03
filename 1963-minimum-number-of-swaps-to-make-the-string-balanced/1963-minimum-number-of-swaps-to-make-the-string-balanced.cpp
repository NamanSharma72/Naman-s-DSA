class Solution {
public:
    int minSwaps(string s) {
        int open = 0 , close = 0;
        int unmatched = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '[') open++;
            else close++;
            if(close > open){
                unmatched++;
                close = open = 0;
            }
        }
        if(unmatched == 0) return 0;
        return unmatched/2 + unmatched%2;
    }
};