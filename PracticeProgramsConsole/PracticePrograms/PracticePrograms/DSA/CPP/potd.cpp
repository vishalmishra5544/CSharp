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
int main()
{
	return 0;
}