class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26 , 0);
        for(int i = 0 ; i<tasks.size() ; i++) freq[tasks[i]-'A']++;
        int maxFreqCount = 0;
        int maxFreq = *max_element(freq.begin() , freq.end());
        for(int i = 0 ; i<freq.size() ; i++) if(freq[i] == maxFreq) maxFreqCount++; 
        int answer = (n+1) * (maxFreq - 1) + maxFreqCount;
        int a = tasks.size();
        return max(a , answer);
    }
};