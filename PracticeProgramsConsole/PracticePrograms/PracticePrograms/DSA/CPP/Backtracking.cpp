#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
    
    void solve(int ind,vector<int> &arr,int n,int r,vector<int> ans){
        if(r==0){
            a.push_back(ans);
            return;
        }
        if(ind>=n) return ;
     
        for(int i=ind; i<n; i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            ans.push_back(arr[i]);
            solve(i+1,arr,n,r-1,ans);
            ans.pop_back();
        }
    
        
        // solve(ind+1,arr,n,r,ans);
    }
    vector<vector<int>> findWays(int n, int r, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>ans;
        solve(0,arr,n,r,ans);
        return a;
    }
int main()
{
    return 0;
}