#include<bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
       if(m>n)
          return -1;
       sort(a.begin(),a.end());
       long long int minimumDiff = INT_MAX,currDiff;
       int i=0,j=m-1;
       while(j<n)
       {
           currDiff = a[j]-a[i];
           minimumDiff = min(minimumDiff,currDiff);
           i++;j++;
       }
       return minimumDiff;
    }
int main()
{
	return 0;
}