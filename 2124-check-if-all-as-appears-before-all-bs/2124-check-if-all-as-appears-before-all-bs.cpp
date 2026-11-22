class Solution {
public:
    bool checkString(string s) {
        int lastA = -2 , firstB = -2;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == 'a') lastA = i;
            if(s[i] == 'b' && firstB == -2) firstB = i;
        }
        return lastA < firstB || firstB == -2;
    }
};