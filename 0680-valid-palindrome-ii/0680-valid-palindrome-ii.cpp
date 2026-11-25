class Solution {
public:
    bool doit(int l , int r , string &s){
        int a = l , b = r;
        while(a <= b){
            if(s[a] != s[b]) return false;
            a++;
            b--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int first = 0 , last = s.size()-1 , chance = 1;
        while(first <= last){
            if(s[first] != s[last]){
                if(chance == 0) return -1;
                else{
                    chance--;
                    bool checkFirst = doit(first+1 , last , s);
                    bool checkLast = doit(first , last-1 , s);
                    if(checkFirst == false && checkLast == false) return false;
                    return true;
                }
            }
            first++;
            last--;
        }
        return true;
    }
};