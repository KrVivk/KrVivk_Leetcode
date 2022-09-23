class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        string ans="";
        string fizz="Fizz";
        string buzz="Buzz";
        for(int i=1;i<=n;i++){
            ans="";
            if(i%3==0) 
                ans+=fizz;
            if(i%5==0) 
                ans+=buzz;
            if(ans.length()==0)
                ans=to_string(i);
            res.push_back(ans);
        }
        return res;
    }
};