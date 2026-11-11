class Solution {
public:
    long long countValidSubstrings(string s) {
        unordered_map<int , int> mpp;
        int lastA = -1;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == 'a') lastA = i;
            if(s[i] == 'b') mpp[i] = lastA;
        }
        int l = 0, r=0;
        long long ans = 0;
        int lastB = -1;
        while(r < s.size()){
            if(s[r] == 'b') lastB = r;
            if(s[r] == 'c'){
                if(lastB >= l && mpp[lastB] >= l){
                    l = mpp[lastB]+1;
                }
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};