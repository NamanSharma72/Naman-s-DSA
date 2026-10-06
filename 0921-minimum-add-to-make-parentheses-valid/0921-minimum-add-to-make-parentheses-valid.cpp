class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0 , close = 0 , count = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '(') open++;
            else close++;
            if(close > open){
                open++;
                count++;
            }
        }
        count+=(open - close);
        return count;
    }
};