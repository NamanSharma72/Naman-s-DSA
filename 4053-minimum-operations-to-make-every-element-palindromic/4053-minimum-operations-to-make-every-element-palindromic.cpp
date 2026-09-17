class Solution {
public:
    int countOpr(vector<long long> &arr , int num){
        int rightSide = lower_bound(arr.begin() , arr.end() , num) - arr.begin();
        int leftSide = rightSide-1;
        return min(abs(num - arr[rightSide]) , abs(num - arr[leftSide]));
    }
    long long minOperations(vector<int>& nums) {
       static vector<long long> oddPal;
       static vector<long long> evenPal;
       if(oddPal.empty()){
            for(int i = 1 ; i<= 99999 ; i++){
                long long even = i , odd = i;
                int num = i;
                int u = 0;
                while(num != 0){
                    int a = num%10;
                    even = even*10 + a;
                    if(u > 0) odd = odd*10 + a;
                    u++;
                    num = num/10;
                }
                if(even%2 == 0) evenPal.push_back(even);
                else oddPal.push_back(even);
                if(odd%2 == 0) evenPal.push_back(odd);
                else oddPal.push_back(odd);
            }
            sort(oddPal.begin() , oddPal.end());
            sort(evenPal.begin() , evenPal.end());
        }
       long long count = 0;
       for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] < 10) count+=0;
            else if(nums[i]%2 == 0) count+=countOpr(evenPal , nums[i]);
            else count+=countOpr(oddPal , nums[i]);
       }
       return count/2;
    }
};