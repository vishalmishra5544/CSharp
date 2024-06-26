 #include<bits/stdc++.h>
 using namespace std;
//https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1
bool isSafe(int r, int c, vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        
        if(r<0 || r>=n || c<0 || c>=m || mat[r][c]==0) return false;
        if(r-1>=0 && mat[r-1][c]==0) return false;
        if(r+1<n && mat[r+1][c]==0) return false;
        if(c-1>=0 && mat[r][c-1]==0) return false;
        if(c+1<m && mat[r][c+1]==0) return false;
        
        return true;
    }
    
    int dfs(int r, int c, vector<vector<int>> &mat, vector<vector<int>> &vis){
        if(c == mat[0].size()-1) return 0;
        
        vis[r][c] = 1;
        int ans = 1e8;
        
        //up
        if(isSafe(r-1,c,mat) && !vis[r-1][c]){
            ans = min(ans,1+dfs(r-1,c,mat,vis));
        }
        
        //down
        if(isSafe(r+1,c,mat) && !vis[r+1][c]){
            ans = min(ans,1+dfs(r+1,c,mat,vis));
        }
        
        //front
        if(isSafe(r,c+1,mat) && !vis[r][c+1]){
            ans = min(ans,1+dfs(r,c+1,mat,vis));
        }
        
        vis[r][c] = 0;
        return ans;
    }
    
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 1e8;
        for(int i=0; i<n; i++){
            if(isSafe(i,0,mat)){
                ans = min(ans,1+dfs(i,0,mat,vis)); 
            }
        }
        if(ans == 1e8) return -1;
        return ans;
    }
//https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1
// Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        // your code here
        long long res[n + 1];

        // base cases
        res[0] = 1;
        res[1] = 1;

        // storing number of ways to reach the ith index as
        // number of ways to reach (i-2)th index +1.
        for (int i = 2; i <= n; i++)
            res[i] = (res[i - 2] + 1);

        // returning the result.
        return res[n];
    }
//https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1
int maxDotProduct(int n, int m, int a[], int b[])
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(0, 0, n, m, a, b, dp);
}
int solve(int i, int j, int n, int m, int a[], int b[], vector<vector<int>> &dp)
{
    if (j == m)
    {
        return 0;
    }
    if (i == n)
    {
        return INT_MIN;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int no_take = 0 + solve(i + 1, j, n, m, a, b, dp);
    int take = a[i] * b[j] + solve(i + 1, j + 1, n, m, a, b, dp);
    return dp[i][j] = max(no_take, take);
}

//https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
long long maximumAmount(int n, int arr[]){
        
      vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
      return recMemo(arr,n,0,n-1,dp);
        
    }
    
    long long recMemo(int arr[],int n,int i,int j,vector<vector<int>> &dp){
        if(i==j) return arr[i];
        if(i+1==j) return max(arr[i],arr[j]);
        if(dp[i][j]!=-1) return dp[i][j];
        long long int choiceI=arr[i]+min(recMemo(arr,n,i+2,j,dp),recMemo(arr,n,i+1,j-1,dp));
        long long int choiceJ=arr[j]+min(recMemo(arr,n,i+1,j-1,dp),recMemo(arr,n,i,j-2,dp));
        return dp[i][j]=max(choiceI,choiceJ);
    }
//https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1
int solve(int i, int j, int m, int n, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
         
        if(i == m-1 && j == n-1)
            return 1 - points[i][j];
        if(i == m || j == n)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        int right = solve(i+1, j, m, n, points, dp);
        int left  = solve(i, j+1, m, n, points, dp);
        return dp[i][j] = max(1, min(right, left) - points[i][j]);
        
    }
    int minPoints(int m, int n, vector<vector<int>> points) 
    { 
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(0, 0, m, n, points, dp);
    } 
//https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1
 int mod=1e9+7;
    int ways(int x, int y)
    {
        //return recursion(x,y);
        // vector<vector<int>> dp(x+1,vector<int> (y+1,-1));
        // return recursionMemo(x,y,dp);
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        return recursionDp(x,y,dp);
    }
    
    int recursion(int x,int y)
    {
       //cout<<x<<" "<<y<<" "<<ans<<endl;
       if(x<0 || y<0)
       {
           return 0;
       }
       if(x+y==0)
       {
         return 1; 
       }
       return recursion(x,y-1)+recursion(x-1,y);
    }
    
    int recursionMemo(int x,int y,vector<vector<int>> &dp)
    {
       if(x<0 || y<0)
       {
           return 0;
       }
       if(x+y==0)
       {
         return 1; 
       }
       if(dp[x][y]!=-1)
         return dp[x][y];
      return dp[x][y]=(recursionMemo(x,y-1,dp) % mod+recursionMemo(x-1,y,dp) % mod) % mod;

    }
    int recursionDp(int x,int y,vector<vector<int>> &dp)
    {
        for(int i=1;i<=x;i++)
          dp[i][0]=1;

        for(int j=1;j<=y;j++)
          dp[0][j]=1;
          
        dp[0][0]=0;
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
               dp[i][j]=(dp[i][j-1] % mod+dp[i-1][j] % mod) % mod;
            }
        }
        return dp[x][y];
    }
 //https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1
 vector<vector<int>> ans;
void solve(vector<int> &arr, int k, int ind, vector<int> &temp)
{
    if (k == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (arr[i] > k)
            break;
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        temp.push_back(arr[i]);
        solve(arr, k - arr[i], i + 1, temp);
        temp.pop_back();
    }
}
vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
{
    vector<int> temp;
    sort(arr.begin(), arr.end());
    solve(arr, k, 0, temp);
    return ans;
}

//https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
const int mod = 1e9+7;
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(auto &e:arr)
          sum+=e;
        if((sum-d)%2==1)
          return 0;
        int half = (sum-d)/2;
        if(half<0)
          return 0;
        vector<vector<int>> dp(n,vector<int> (half+1,-1));
        return solveRecursion(half,0,n,arr,0,dp)%mod;
    }
    
    int solveRecursion(int sum,int temp,int n,vector<int> &arr,int index,vector<vector<int>> &dp)
    {
        if(index==n||temp>sum)
        {
            if(sum==temp)
              return 1;
            return 0;
        }
        if(dp[index][temp]!=-1)
          return dp[index][temp]%mod;
        int ans=0;
        ans+=solveRecursion(sum,temp+arr[index],n,arr,index+1,dp);
        ans+=solveRecursion(sum,temp,n,arr,index+1,dp);
        return dp[index][temp]=ans%mod;
    }

int main()
{
    vector<vector<int>> mat(5,vector<int> (5,1));
    mat[0][1]=0;
    mat[3][3]=mat[4][4]=0;
    int ans =findShortestPath(mat);
    
    return 0;
}