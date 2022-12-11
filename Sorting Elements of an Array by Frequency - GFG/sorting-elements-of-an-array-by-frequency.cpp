#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second!=p2.second){
        return p1.second>p2.second;
    }
    return p1.first<p2.first;
}

vector<int> customSort(vector<int>& arr){
    int freq[60];
    for(int i=0;i<60;i++){
        freq[i]=0;
    }
    for(int i=0;i<arr.size();i++){
        freq[arr[i]-1]++;
    }
    vector<pair<int,int>> vec;
    for(int i=0;i<arr.size();i++){
        vec.push_back({arr[i],freq[arr[i]-1]});
    }
    sort(vec.begin(),vec.end(),cmp);
    vector<int> ans;
    for(int i=0;i<vec.size();i++){
        ans.push_back(vec[i].first);
    }
    return ans;
}

int main() {
int t;
cin>>t;
while(t--){
   int n;
   cin>>n;
   vector<int> arr;
   for(int j=0;j<n;j++){
       int x;
       cin>>x;
       arr.push_back(x);
   }
  vector<int> ans= customSort(arr);
   for(int k=0;k<n;k++){
       cout<<ans[k]<<" ";
   }
   cout<<endl;
}
return 0;
}