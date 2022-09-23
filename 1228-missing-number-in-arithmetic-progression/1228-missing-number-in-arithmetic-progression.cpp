class Solution {
public:
    int missingNumber(vector<int>& arr) 
    {
        int n = arr.size();
         // 1. Get the difference `difference`.
        int difference = (arr.back() - arr.front()) / n;

        // 2. The expected element equals the starting element.
        int expected = arr.front();

        for (int &val : arr) {
            // Return the expected value that doesn't match val.
            if (val != expected) 
                return expected;

            // Next element will be expected element + `difference`.
            expected += difference;
        }
        return expected;
    }
};