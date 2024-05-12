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
int main()
{
	return 0;
}