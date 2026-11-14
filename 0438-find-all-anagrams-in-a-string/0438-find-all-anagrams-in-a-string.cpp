class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqP(26 , 0);
        vector<int> freqS(26 , 0);
        for(int i = 0 ; i<p.size() ; i++) freqP[p[i]-'a']++;
        int l = 0 , r = 0;
        vector<int> ans;
        while(r < s.size()){
            freqS[s[r]-'a']++;
            while(freqS[s[r]-'a'] > freqP[s[r]-'a']){
                freqS[s[l]-'a']--;
                l++;
            }
            if(freqP == freqS) ans.push_back(l);
            r++;
        }
        return ans;
    }
};