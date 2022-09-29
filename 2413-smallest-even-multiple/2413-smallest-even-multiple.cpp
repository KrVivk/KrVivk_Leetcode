class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n << (n & 1);
    }
};

/*
if n is even, return n << 0
if n is odd, return n << 1 */