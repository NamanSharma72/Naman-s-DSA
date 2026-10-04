class Solution {
public:
    bool checkValidString(string s) {
        int lowestUnmatch = 0 , highestUnmatch = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '('){
                lowestUnmatch++;
                highestUnmatch++;
            }
            else if(s[i] == ')'){
                lowestUnmatch--;
                highestUnmatch--;
            }
            else{
                lowestUnmatch--;
                highestUnmatch++;
            }
            if(highestUnmatch < 0) return false;
            lowestUnmatch = max(lowestUnmatch , 0);
        }
        return lowestUnmatch == 0;
    }
};