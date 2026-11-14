class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string , int> mppW;
        for(int i = 0 ; i<words.size() ; i++) mppW[words[i]]++;
        int wordLength = words[0].size();
        vector<int> ans;
        int required = mppW.size();
        for(int offset = 0 ; offset < wordLength ; offset++){
            int matching = 0;
            unordered_map<string , int> mppS;
            int l = offset , r = offset;
            while(r+wordLength-1 < s.size()){
                string word = "";
                    word = s.substr(r , wordLength);
                    mppS[word]++;
                    if(mppW.find(word) != mppW.end() && mppS[word] == mppW[word]) matching++;
                    while(mppS[word] > mppW[word]){
                        string word1 = s.substr(l , wordLength);
                        if(mppW.find(word1) != mppW.end() && mppS[word1] == mppW[word1]) matching--;
                        mppS[word1]--;
                        l+=wordLength;
                    }
                    if(matching == required) ans.push_back(l);
                r+=wordLength;
            }
        }
        return ans;
    }
};