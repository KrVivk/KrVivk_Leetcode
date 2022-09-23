class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size(), water = 0, i; 
      vector<int> pMax(n), sMax(n); 
     
      pMax[0] = height[0];
      sMax[n-1] = height[n-1]; 
      for( i = 1; i < n; i++){
        pMax[i] = max(height[i], pMax[i-1]);
      }
       for(i = n-2; i>=0; i--){
        sMax[i] = max(height[i], sMax[i+1]);
      }
       
      for(i = 0; i < n; i++){
        water += max(0, min(pMax[i], sMax[i])-height[i]);
      }
      return water;
        
    }
};

