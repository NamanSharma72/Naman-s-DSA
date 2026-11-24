class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int mod = 1e9+7;
        stack<int> st;
        vector<int> nextSmaller(nums.size() , nums.size());
        for(int i = nums.size()-1 ; i>=0 ; i--){
            if(st.empty()) st.push(i);
            else{
                while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
                if(!st.empty()) nextSmaller[i] = st.top();
            }
            st.push(i);
        }
        stack<int> st1;
        vector<int> prevSmaller(nums.size() , -1);
        for(int i = 0 ; i<nums.size(); i++){
            if(st1.empty()) st1.push(i);
            else{
                while(!st1.empty() && nums[st1.top()] > nums[i]) st1.pop();
                if(!st1.empty()) prevSmaller[i] = st1.top();
            }
            st1.push(i);
        }
        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            long long  L = i-prevSmaller[i] , R = nextSmaller[i] - i;
            ans = (ans + 1LL*nums[i]*L*R)%mod;
        }
        return ans%mod;
    }
};