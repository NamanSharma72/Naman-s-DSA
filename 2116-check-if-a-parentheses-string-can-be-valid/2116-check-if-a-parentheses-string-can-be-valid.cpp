class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2 != 0) return false;
        for(int i = 0 ; i<s.size() ; i++) if(locked[i] == '0') s[i] = '*';
        int lowestUnmatched = 0 , highestUnmatched = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '('){
                lowestUnmatched++;
                highestUnmatched++;
            }
            else if(s[i] == ')'){
                lowestUnmatched--;
                highestUnmatched--;
            }
            else{
                lowestUnmatched--;
                highestUnmatched++;
            }
            if(highestUnmatched < 0) return false;
            lowestUnmatched = max(lowestUnmatched , 0);
        }
        return lowestUnmatched == 0;
    }
};