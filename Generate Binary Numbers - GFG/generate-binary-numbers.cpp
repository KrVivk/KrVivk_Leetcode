//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{ 
  queue<string>q;
  q.push("1");
  int count = 0 ;
  vector<string>ans;
  while(count < N){
      string x = q.front();
      q.pop();
      q.push(x + "0");
      q.push(x + "1");
      ans.push_back(x);
      count++;
  }
  return ans;
}


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends