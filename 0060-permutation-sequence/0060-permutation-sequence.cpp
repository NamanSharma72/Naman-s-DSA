class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        for(int i = 1 ; i<=n ; i++) arr.push_back(i);
        while(k > 1){
            next_permutation(arr.begin() , arr.end());
            k--;
        }
        string ans = "";
        for(int i = 0 ; i<n ; i++) ans+=(arr[i]+'0');
        return ans;
    }
};