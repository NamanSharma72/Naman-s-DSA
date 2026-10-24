class Solution {
public:
    int countMagicalPairs(string s) {
        int count = 0;
        for(int i = 0 ; i<s.size() ; i++){
            vector<int> freq(26 , 0);
            unordered_map<int , int> store;
            int distinct = 0;
            for(int j = i ; j>=0 ; j--){
                if(freq[s[j]-'a'] == 0) distinct++;
                store[distinct]++;
                freq[s[j]-'a']++;
            }
            vector<int> freq2(26 , 0);
            int distinct2 = 0;
            for(int k = i+1 ; k<s.size() ; k++){
                if(freq2[s[k]-'a'] == 0) distinct2++;
                if(store.find(distinct2) != store.end()) count+=store[distinct2];
                freq2[s[k]-'a']++;
            }
        }
        return count;
    }
};