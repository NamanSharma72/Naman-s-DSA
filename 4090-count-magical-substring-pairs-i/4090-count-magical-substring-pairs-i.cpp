class Solution {
public:
    int countMagicalPairs(string s) {
        int size = s.size() , count = 0;
        for(int j = 0 ; j<size ; j++){
            unordered_map<int , int> freqDistinctIJ;
            int countDistinctIJ = 0;
            vector<int> freqIJ(26 , 0);
            for(int i = j ; i>=0 ; i--){
                if(freqIJ[s[i]-'a'] == 0) countDistinctIJ++;
                freqIJ[s[i]-'a']++;
                freqDistinctIJ[countDistinctIJ]++;
            }
            int countDistinctJK = 0;
            vector<int> freqJK(26 , 0);
            for(int k = j+1 ; k<size ; k++){
                if(freqJK[s[k]-'a'] == 0) countDistinctJK++;
                freqJK[s[k]-'a']++;
                count+=freqDistinctIJ[countDistinctJK];
            }
        }
        return count;
    }
};