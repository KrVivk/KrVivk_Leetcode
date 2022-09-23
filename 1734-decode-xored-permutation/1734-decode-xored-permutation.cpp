class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        // f(n)  = 1^2^3^4^5 .... ^n ( n is odd number)
        int nxor = (encoded.size() / 2 + 1) % 2 ;
        
        // f(m) = p2^p3^p4....pn (without p1) 
        int mxor = encoded[1];
        for (int i=3; i< encoded.size(); i+=2) {
            mxor ^= encoded[i];
        }
        
        // p[0] = f(n) ^ f(m) 
        int x = nxor ^ mxor;
        
        vector<int> result;
        result.push_back(x);
        
        // we know, encoded[i] = p[i] ^ p[i+1]
        // so, p[i+1] = p[i] ^ encoded[i]
        for (int i=0; i< encoded.size(); i++) {
            x = x ^ encoded[i];
            result.push_back(x);
        }
        
        return result;
    }
};