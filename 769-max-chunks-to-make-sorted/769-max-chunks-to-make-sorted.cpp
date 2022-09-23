class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cmax=INT_MIN;
        int chunk=0;
        for(int i=0;i<arr.size();i++){
            cmax=max(cmax,arr[i]);
            if(cmax==i)chunk++;
        }
        return chunk;
    }
};

