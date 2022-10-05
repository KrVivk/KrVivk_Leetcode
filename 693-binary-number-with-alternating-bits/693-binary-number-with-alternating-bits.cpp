class Solution {
public:
    bool hasAlternatingBits(int n) {
       string bits = bitset<31>(n).to_string();
       int j = 0;
       while(bits[j] == '0'){
            ++j;
        }
        bits.erase(0, j);
        for (int i = 0; i < bits.size() - 1; i++) {
            if (bits.at(i) == bits.at(i+1)) {
                return false;
            }
        }
        return true;
    }
};
