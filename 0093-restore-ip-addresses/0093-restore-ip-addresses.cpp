class Solution {
    vector<string> ans;
public:
     void restoreDFS(string s, string temp, int dot, int index) {
        if (index == s.size() and dot == 4) {
            temp.pop_back();
            ans.push_back(move(temp));
            return;
        }
        if (index >= s.size() or dot >= 4) {
            return;
        }
        restoreDFS(s, temp + s[index] + '.', dot + 1, index + 1);
        if (s[index] != '0') {
            restoreDFS(s, temp + s.substr(index, 2) + '.', dot + 1, index + 2);
        }
		
        if (s[index] != '0' and (stoi(s.substr(index, 3)) < 256)) {
            restoreDFS(s, temp + s.substr(index, 3) + '.', dot + 1, index + 3);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12 or s.size() < 4) return ans;
        restoreDFS(s, "", 0, 0);
        return ans;
    }
};