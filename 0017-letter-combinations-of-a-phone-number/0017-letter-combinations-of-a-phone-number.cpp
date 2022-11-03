class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mp { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" },ans;
    
            for (int i = 0; i < digits.size(); i++){
                int n = ans.size();
                for (int j = 0; j < mp[digits[i] - '0'].size(); j++) {
                    string str = mp[digits[i] - '0'];

                    if (i == 0){
                        string s = "";
                        s += str[j];
                        ans.push_back(s);
                    }
                    else{

                        for (int k = 0; k < n; k++){
                            if (j == 0)ans[k] += str[j];
                            else {
                                string ss = ans[k];
                                ss.pop_back();
                                ss += str[j];
                                ans.push_back(ss);
                            }
                        }
                    }
                }
            }
        return ans;
    }
};
        