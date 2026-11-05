class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin() , arr2.end());
        int count = 0;
        for(int i = 0 ; i<arr1.size() ; i++){
            int low = 0 , high = arr2.size()-1 , minDiff = INT_MAX;
            while(low <= high){
                int mid = (high+low)/2;
                if(arr1[i] == arr2[mid]){
                    minDiff = 0;
                    break;
                }
                else if(arr1[i] < arr2[mid]){
                    if(abs(arr2[mid]-arr1[i]) < minDiff){
                        minDiff = arr2[mid]-arr1[i];
                    }
                    high = mid-1;
                }
                else{
                    if(abs(arr2[mid]-arr1[i]) < minDiff){
                        minDiff = arr1[i]-arr2[mid];
                    }
                    low = mid+1;
                }
            }
            if(minDiff > d) count++;
        }
        return count;
    }
};