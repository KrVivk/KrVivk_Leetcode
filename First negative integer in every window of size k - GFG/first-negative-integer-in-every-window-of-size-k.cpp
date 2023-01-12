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
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
    // A Double Ended Queue, Di that will store indexes of
    // useful array elements for the current window of size k.
    // The useful elements are all negative integers.
    deque<long long int> dq;
    vector<long long> ans;

    /* Process first k (or first window) elements of array */
    long long int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0) dq.push_back(i);

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; i++) {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!dq.empty()) ans.push_back(arr[dq.front()]);

        // else the window does not have a
        // negative integer
        else
            ans.push_back(0);

        // Remove the elements which are out of this window
        while ((!dq.empty()) && dq.front() < (i - k + 1))
            dq.pop_front(); // Remove from front of queue

        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0) dq.push_back(i);
    }

    // Print the first negative
    // integer of last window
    if (!dq.empty())
        ans.push_back(arr[dq.front()]);
    else
        ans.push_back(0);

    return ans;
}