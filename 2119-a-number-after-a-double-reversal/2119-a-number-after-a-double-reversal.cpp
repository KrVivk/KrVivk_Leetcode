class Solution {
public:
    bool isSameAfterReversals(int num) {
/* every no. reversed even number of times = that no.*/
        return num == 0 || num % 10;
    }
};