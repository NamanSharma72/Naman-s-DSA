class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int index = 0;
        stack<pair<int , int>> st;
        while(index < colors.size()){
            if(st.empty()){
                if(groupSize[types[index]] > 1){
                    st.push({index , 1});
                }
            }
            else if(colors[st.top().first] == colors[index] && types[st.top().first] == types[index]){
                if(st.top().second+1 == groupSize[types[index]]){
                    st.pop();
                }
                else {
                    int ele = st.top().second;
                    st.pop();
                    st.push({index , ele+1});
                }
            }
            else{
                if(groupSize[types[index]] > 1) st.push({index , 1});
            }
            index++;
        }
        return st.empty();
    }
};