class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int> st;
        long long ans = 0;
        for (int x : nums) {
            // Count eligible previous values < x
            int cnt = lower_bound(st.begin(), st.end(), x) - st.begin();
            ans += cnt;
            // x invalidates all previous values > x
            while (!st.empty() && st.back() > x) st.pop_back();
            // x itself becomes eligible for future elements
            st.push_back(x);
        }
        return ans;
    }
};