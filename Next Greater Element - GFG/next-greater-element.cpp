//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long>nge(n);
        stack<long long>s;
        s.push(0);
        for(long long i=1;i<n;i++){
            while(!s.empty() && arr[i]>arr[s.top()]) {
                nge[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            nge[s.top()]=-1;
            s.pop();
        }
        return nge;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends