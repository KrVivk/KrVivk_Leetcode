//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    void sort(int arr[], int n)
    {
        // your code here
        vector<int> ans;
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++)
        {
            int blk=arr[i]/n;
            v[blk].push_back(arr[i]);
        }
        int tmp[n+1]={0};
        for(int i=0;i<n;i++)
        {
            int st=0+i*n;
            int en=n-1+st;
            
            for(auto j:v[i])
            {
                tmp[j-st]++;
            }
            
            for(int j=0;j<n;j++)
            {
                while(tmp[j]>0){
                ans.push_back(st+j);
                tmp[j]--;
                }
            }
            
        }
        for(int i=n-1;i>=0;i--)
        {
            arr[i]=ans[i];   
        }
    }
};

//{ Driver Code Starts.
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


// Driver program to test above functions
int main()
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		Solution ob;
		ob.sort (arr, n);
		print (arr, n);
		cout << endl;
	}
}




// } Driver Code Ends