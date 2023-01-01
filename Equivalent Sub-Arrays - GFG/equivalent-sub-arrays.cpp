//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
public:

int countDistinctSubarray(int arr[], int n)
{
    unordered_map <int,int> tmp;
    for (int i = 0; i < n; ++i)
        tmp[arr[i]] = 1;
    int k = tmp.size();
    tmp.clear();
    int ans = 0, right = 0, window = 0;
    for (int left = 0; left < n; ++left)
    {
        while (right < n && window < k)
        {
            ++tmp[arr[right]];
            if (tmp[ arr[right] ] == 1)
                ++window;
            ++right;
        }
        if (window == k)
            ans += (n - right + 1);
        --tmp[ arr[left] ];
        if (tmp[arr[left]] == 0)
                --window;
    }
    return ans;
}

};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends