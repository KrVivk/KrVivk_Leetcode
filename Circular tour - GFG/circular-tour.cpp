//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n) {
        //Your code here
        int petrolHas = 0;
        deque < int > q;
        vector < bool > startingPoint(n, false);
        int i = 0;
        int ans = -1;
        bool notFound = false;
        bool Found = false;
        while (true) {
 
            if (q.empty() and startingPoint[i] == true) {
                // to prevent from reconsidering a petrol pump which has been previously tested as a starting point for a complete
                notFound = true;
                break;
            }
            if (q.size() == n) {
                // if it contains all n elements then it is a correct point for covering a circle
                Found = true;
                break;
            }
            // check if petrol of this petrol pump+ prevPetrol stored is enough for covering the distance to next petrol pump or not
            int added = p[i].petrol + petrolHas;
 
            if ((added - p[i].distance) < 0) {
                // marking these petrol pumps as useless starting point
                if (q.empty()) {
                    startingPoint[i] = true;
                }
                while (!q.empty()) {
                    // marking these petrol pump useless as they can never be starting point as the current petrol pump does not suffice conditions.
                    int index = q.front();
                    if (startingPoint[index] == false) {
                        startingPoint[index] = true;
                    }
                    q.pop_front();
                }
                petrolHas = 0;
            } else {
                // adding a potiential starting point for covering the whole circle.
                if (q.empty()) {
                    q.push_back(i);
                    startingPoint[i] = true;
                    petrolHas += (p[i].petrol - p[i].distance);
                } else {
                    q.push_back(i);
                    petrolHas += (p[i].petrol - p[i].distance);
                }
            }
            // moving in a circular manner
            i = (i + 1) % n;
        }
 
        if (notFound) {
            return ans;
        }
 
        ans = q.front();
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends