class Solution {
public:
    int minInsertions(string s) {
        int open = 0 , ans = 0 , close = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '(') open++;
            if(s[i] == ')'){
                if(i+1 < s.size() && s[i+1] == ')'){
                   if(open > 0) open--;
                   else ans++;
                   i++;
                }
                else{
                    if(open > 0){
                        open--;
                        ans++;
                    }
                    else ans+=2;
                }
            }
        }
        cout << open << " " << close;
        return ans + 2*open;
    }
};