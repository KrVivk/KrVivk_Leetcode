class Solution {
public:
     void right_rotate(string &s, int i, int j)
    {
        if(i==j)return;
        char a=s[j];
        while(j>i)
        {
            s[j]=s[j-1];
            j--;
        }
        s[i]=a;
        
    }
    void left_rotate(string&s,int i, int j)
    {
        if(i==j)return;
        char a=s[i];
        while(i<j)
        {
            s[i]=s[i+1];
            i++;
        }
        s[j]=a;
    }
    void fun(string &s, vector<string>&ans, int i, int n)
    {
        if(i==n-1)
        {
            ans.push_back(s);
            return ;
        }
        for(int j=i;j<n;j++)
        {
            right_rotate(s,i,j); 
            fun(s,ans,i+1,n);
            left_rotate(s,i,j);
        }
    }
    string getPermutation(int n, int k) {
        vector<string>ans;
        string s="";
        for(int i=1;i<=n;i++)
        {
            char a='0'+i;
            s+=a;
        }
        int i=0;
        fun(s,ans,i,n);
        return ans[k-1];
        
    }
};