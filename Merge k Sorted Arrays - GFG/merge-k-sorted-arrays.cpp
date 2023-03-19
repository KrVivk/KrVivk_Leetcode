//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


vector<vector<int>> arr1;
class Solution
{
public:
    // Function to merge k sorted arrays.
    //  vector<vector<int>> arr1;
 
    struct cmp
 
    {
 
        bool operator()(pair<int, int> &p1, pair<int, int> &p2)
 
        {
 
            int v1 = arr1[p1.first][p1.second];
 
            int v2 = arr1[p2.first][p2.second];
 
            return v1 > v2;
        }
    };
 
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
 
    {
        arr1.resize(arr.size(), vector<int>(arr[0].size()));
        for (int i = 0; i < arr.size(); i++)
 
        {
 
            for (int j = 0; j < arr[0].size(); j++)
 
            {
 
                arr1[i][j] = arr[i][j];
            }
        }
 
        // code here
 
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
 
        for (int i = 0; i < k; i++)
            q.push({i, 0});
 
        vector<int> ans;
 
        while (!q.empty())
 
        {
 
            pair<int, int> v = q.top();
 
            q.pop();
 
            int i = v.first;
 
            int j = v.second;
 
            ans.push_back(arr1[i][j]);
 
            if (k > j + 1)
 
                q.push({i, j + 1});
        }
 
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends