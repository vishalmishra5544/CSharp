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
int main()
{
	return 0;
}