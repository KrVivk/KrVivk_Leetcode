//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isSafe(int x, int y, vector<vector<int>>&matrix){
		int n = matrix.size();
		return (x >= 0 and x < n and y >=0 and y < n and matrix[x][y] != 0);
	}
	bool helper(int x, int y, vector<vector<int>>&matrix, vector<vector<int>>&sol){
		int n = matrix.size();
		if(x == n-1 and y == n-1){
			sol[x][y] = 1;
			return true;
		}
		if(isSafe(x, y, matrix)){
			sol[x][y] = 1;
			for(int step = 1; step <= matrix[x][y] and step < n; step++){
				if(helper(x, y+step, matrix, sol))
					return true;
				if(helper(x+step, y, matrix, sol))
					return true;
			}
			sol[x][y] = 0;
			return false;
		}
		return false;
	}
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
		int  n = matrix.size();
		vector<vector<int>>sol(n, vector<int>(n, 0));
		helper(0, 0, matrix, sol);
		vector<vector<int>>ans;
		ans.push_back({-1});
		return sol[n-1][n-1] == 0 ? ans : sol;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends