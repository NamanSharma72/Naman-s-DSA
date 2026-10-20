class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (long long k = 1;  k * (k + 1) / 2 <= n; k++) {
            long long rem = n - k * (k - 1) / 2;
            if (rem % k == 0) count++;
        }
        return count;
    }
};