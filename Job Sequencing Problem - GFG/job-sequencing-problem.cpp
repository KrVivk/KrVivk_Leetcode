//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comparison(Job a, Job b) 
    { 
    	return (a.profit > b.profit); 
    } 
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int res = 0, count = 0;
    	sort(arr, arr+n, comparison); 
    
    	int result[n];
    	bool slot[n]; 
    
    	for (int i=0; i<n; i++) 
    		slot[i] = false; 
    
    	for (int i=0; i<n; i++) 
    	{ 
        	for (int j=min(n, arr[i].dead)-1; j>=0; j--) 
        	{ 
        		if (slot[j]==false) 
        		{ 
        			result[j] = i;  
        			slot[j] = true; 
        			break; 
        		} 
        	} 
    	} 
    
    	for (int i=0; i<n; i++)
    	{ 
        	if (slot[i]) {
        	    count++;
        	    res += arr[result[i]].profit;
        	}
    	}
    	vector<int> ans;
    	ans.push_back(count);
    	ans.push_back(res);
    	return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends