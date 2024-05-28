#include<bits/stdc++.h>
using namespace std;
vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> ans;
        ans.push_back(n);
        
        while(n!=1)
        {
            if((n&1)==0)
              n=sqrt(n);
            else
              n=sqrt(n)*n;
            ans.push_back(n);
        }
        return ans;
    }
//https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1
int solve(int source, int step, int dest)
    {
        // base cases
        if (abs(source) > (dest))
            return INT_MAX;
        if (source == dest)
            return step;

        // at each point we can go either way

        // if we go on positive side
        int pos = solve(source + step + 1, step + 1, dest);

        // if we go on negative side
        int neg = solve(source - step - 1, step + 1, dest);

        // minimum of both cases
        return min(pos, neg);
    }

    int minSteps(int D)
    {
        // code here
        return solve(0, 0, D);
    }
//https://www.geeksforgeeks.org/problems/you-and-your-books/1
long long max_Books(int arr[], int n, int k) {
       long long int maxi=0,curr=0;
       int found=0;
       for(int i=0;i<n;i++)
       {
           if(arr[i]<=k)
           {
               curr+=arr[i];
           }
           else
           {
               curr=0;
           }
           maxi=max(maxi,curr);
       }
       return maxi;
    }
//https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1
//Memoization
    // int fun(string &s1,string &s2,int c1,int c2,int i,int j, vector<vector<int>> &dp)
    // {
    //     if(i==s1.length() && j==s2.length())
    //     {
    //         return 0;
    //     }
    //     if(i==s1.length() && j!=s2.length())
    //     {
    //         return (s2.length()-j)*c2;
    //     }
    //     if(i!=s1.length() && j==s2.length())
    //     {
    //         return (s1.length()-i)*c1;
    //     }
        
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
        
    //     int cost=0;
    //     if(s1[i]==s2[j])
    //         cost=fun(s1,s2,c1,c2,i+1,j+1,dp);
    //     else 
    //         cost=min(c1+fun(s1,s2,c1,c2,i+1,j,dp),c2+fun(s1,s2,c1,c2,i,j+1,dp));
        
    //     return dp[i][j]=cost;
    // }
    //Tabulation
    int findMinCost(string X, string Y, int costX, int costY) {
        
        int n=X.size();
        int m=Y.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(X[i-1]==Y[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int c1=(n-dp[n][m])*costX;
        int c2=(m-dp[n][m])*costY;
        return c1+c2;
     
    }
//https://www.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1
int helper(int n , vector<int> & a , int prev){
        if(n == 0) return 0 ; 
        
        //pick 
        int pick = 0 ; 
        if(prev == -1 || abs(a[n-1] - prev) == 1)
            pick = 1 + helper(n-1 , a  , a[n-1]) ; 
        
        //not pick
        int notPick =  helper(n - 1 , a , prev) ;
        
        return max(pick , notPick) ; 
    }
    int longestSubseq(int n, vector<int> &a) {
        return helper(n , a , -1) ;
    }
//https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1
 vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;
    
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= w; j++)
                dp[j] = min(dp[j], cost[i] + dp[j - i - 1]); 
    
        return dp[w];
int main()
{
	return 0;
}