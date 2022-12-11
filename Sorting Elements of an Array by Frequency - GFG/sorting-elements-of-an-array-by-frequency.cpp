#include <bits/stdc++.h>

using namespace std;

 

bool mycomp(pair<int,int> a,pair<int,int> b)

{

    if(a.second>b.second)

    {

        return true;

    }

    else if(a.second == b.second)

    {

        return a.first<b.first;

    }

    else{

        return false;

    }

}

 

int main() {

 //code

 int t;

    cin >> t;

    for(int i=0;i<t;i++)

    {

        int n;

        cin >> n;

        vector <pair <int ,int>> ans;

        map<int,int> m;

        vector <int> arr;

        for(int i=0;i<n;i++)

        {

            int x;

            cin >> x;

            arr.push_back(x);

        }

        for(int i=0;i<n;i++)

        {

            m[arr[i]]++;

        }

        for(auto i : m)

        {

            ans.push_back({i.first,i.second});

        }

        sort(ans.begin(),ans.end(),mycomp);

        for(auto i: ans){

            while(i.second--)

            {

                cout << i.first<<" ";

            }

        }

        cout << endl;

    }

}