class Solution {
public:
    int divisorsSum(int num) {
        vector<int> divs;
        // Iterate up to the square root inclusive
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                if (i * i == num) {
                    divs.push_back(i);
                } else {
                    divs.push_back(i);
                    divs.push_back(num / i);
                }
            }
            // Optimization: if we exceed 4 divisors, we can stop
            if (divs.size() > 4) break;
        }

        // Check if the count is exactly 4
        if (divs.size() == 4) {
            int s = 0;
            for (int d : divs) s += d;
            return s;
        }
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        for (int n : nums) {
            totalSum += divisorsSum(n);
        }
        return totalSum;
    }
};