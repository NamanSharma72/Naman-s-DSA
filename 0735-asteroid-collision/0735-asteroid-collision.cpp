class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        for(int i = 0 ; i<nums.size() ; i++){
            int flag = 0;
            while(!st.empty() && st.top() > 0 && nums[i] < 0){
                if(abs(nums[i]) == st.top()){
                    flag = 1;
                    st.pop();
                    break;
                }
                else if(abs(nums[i]) < st.top()){
                    flag = 1;
                    break;
                }
                else st.pop();
            }
            if(flag == 0) st.push(nums[i]);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};