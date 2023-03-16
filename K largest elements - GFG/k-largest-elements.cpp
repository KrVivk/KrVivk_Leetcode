//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        //implementing MinHeap using priority queue.
        priority_queue<int, vector<int>, greater<int> > q;
        vector<int> v;
        
        for(int i = 0; i < n;i++)
        {
            //if size of priority queue becomes equal to k,
            if(q.size() == k)
            { 
                //if top element is smaller than arr[i], we pop the front 
                //element from priority queue and push arr[i] in priority queue.
                if(q.top() < arr[i])
                { 
                    q.pop();   
                    q.push(arr[i]);  
                }
            }
            //else we just push arr[i] in priority queue.
            else
                q.push(arr[i]);
        }
        
        //while priority queue is not empty, we keep storing the top element 
        //in list and keep popping it from the priority queue.
        while(!q.empty())
        v.push_back(q.top()), q.pop(); 
        
        //reversing the list and returning it.
        reverse(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends