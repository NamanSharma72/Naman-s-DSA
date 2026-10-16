class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int , int> freq;
        for(int i = 0 ; i<tasks.size() ; i++) freq[tasks[i]]++;
        int ans = 0;
        for(auto &it : freq){
            if(it.second == 1) return -1;
            int count = it.second/3;
            int left = it.second - count*3;
            if(left > 0) count++;
            ans+=count;
        }
        return ans;
    }
};