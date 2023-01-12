//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


// function to find the first negative
// integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int k) {
   deque<long long int>q;
   for(int i=0;i<k;i++){
       if(A[i]<0){
           q.push_back(i);
       }
   }
   vector<long long >v;
   for(int i=k;i<N;i++){
       if(q.empty()){
           v.push_back(0);
       }else{
           v.push_back(A[q.front()]);
       }
       if(!q.empty() and q.front()==(i-k)){
           q.pop_front();
       }
       if(A[i]<0){
           q.push_back(i);
       }
   }
   
   if(!q.empty()){
       v.push_back(A[q.front()]);
   }else{
       v.push_back(0);
   }
   return v;
}