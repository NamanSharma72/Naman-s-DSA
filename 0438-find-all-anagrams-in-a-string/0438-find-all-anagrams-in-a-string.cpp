class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqP(26 , 0);
        vector<int> freqS(26 , 0);
        int distinct = 0;
        for(int i = 0 ; i<p.size() ; i++) {
            if(freqP[p[i]-'a'] == 0) distinct++;
            freqP[p[i]-'a']++;
        }
        int l = 0 , r = 0;
        vector<int> ans;
        int matching = 0;
        while(r < s.size()){
            freqS[s[r]-'a']++;
            if(freqS[s[r]-'a'] == freqP[s[r]-'a']) matching++;
            while(freqS[s[r]-'a'] > freqP[s[r]-'a']){
                if(freqS[s[l]-'a'] == freqP[s[l]-'a']) matching--;
                freqS[s[l]-'a']--;
                l++;
            }
            if(matching == distinct) ans.push_back(l);
            r++;
        }
        return ans;
    }
};