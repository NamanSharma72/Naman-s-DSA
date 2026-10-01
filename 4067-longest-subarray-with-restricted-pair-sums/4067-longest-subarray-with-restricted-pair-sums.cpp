class Solution {
public:
    bool isInvalid(vector<int>& freq, int x) {
        for (int d = 1; d <= 500; d++) {
            if (freq[d] == 0) continue;

            // Case 1: d + other = x
            int other = x - d;

            if (other >= 1 && other <= 500) {
                if (other == d && freq[d] >= 2)
                    return true;

                if (other != d && freq[other] > 0)
                    return true;
            }

            // Case 2: d + x = t
            int t = x + d;

            if (t <= 500 && freq[t] > 0)
                return true;
        }

        return false;
    }

    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int ans = 0;

        vector<int> freq(501, 0);

        for (int right = 0; right < n; right++) {

            while (left < right && isInvalid(freq, nums[right])) {
                freq[nums[left]]--;
                left++;
            }

            freq[nums[right]]++;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};