    #include<bits/stdc++.h>
    using namespace std;

    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeating,missing;
        for(int i=0;i<n;i++)
        {
            int index = abs(arr[i])-1;
            if(arr[index]<0)
              repeating = index + 1;
            else
              arr[index] *=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
              missing = i+1;
        }
        return {repeating,missing};
    }
    int gcdOfNNumbers(int N, int arr[])
    {
    	// Your code goes here
    	int res=arr[0];
    	for(int i=1;i<N;i++)
    	{
    	    res=gcd(arr[i],res);
    	    if(res==1)
    	      return 1;
    	}
    	return res;
    }
    int gcd(int a,int b)
    {
        while(a!=b)
        {
            if(a>b)
              a=a-b;
            else
              b=b-a;
        }
        return a;
    }
    //https://www.geeksforgeeks.org/problems/three-great-candidates0515/1?page=11&difficulty=Easy&sortBy=submissions
long long maxProductOf3Numbers(int ar[], int n) {
        // code here
        long long mx1{INT_MIN}, mx2{INT_MIN}, mx3{INT_MIN}, m1{INT_MAX}, m2{INT_MAX};
        
        for(int i=0; i < n; i++) {
            if(ar[i] > mx1) mx3 = mx2, mx2 = mx1, mx1 = ar[i];
            else if(ar[i] > mx2) mx3 = mx2, mx2 = ar[i];
            else if(ar[i] > mx3) mx3 = ar[i];
            if(ar[i] < m1) m2 = m1, m1 = ar[i];
            else if(ar[i] < m2) m2 = ar[i];
        }
        
        return max(m1 * m2 * mx1, mx1 * mx2 * mx3);
    }
//https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1?page=10&difficulty=Easy&sortBy=submissions
vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        vector<int> sieve;
        vector<int> ans(n+1,1);
        ans[0]=0;
        ans[1]=0;
        for(int i=4;i<=n;i+=2)
         ans[i]=0;
        for(int i=6;i<=n;i+=3)
         ans[i]=0;
        for(int i=5;i*i<=n;i+=6)
        {
            for(int j=i*i;j<=n;j+=i)
              ans[j]=0;
            for(int j=(i+2)*(i+2);j<=n;j+=(i+2))
              ans[j]=0; 
        }
        for(int i=2;i<=n;i++)
        {
            if(ans[i]&1==1)
              sieve.push_back(i);
        }
        return sieve;
    }

int isLeap(int N){
        //code here
      if(N%400==0){
       return 1;
       }
       else if((N%4==0)&&(N%100!=0)){
           return 1;
       }
       else{
           return 0;
       }
    }

//https://www.geeksforgeeks.org/problems/print-the-kth-digit3520/1?page=2&difficulty=Basic&status=unsolved&sortBy=submissions
int kthDigit(int A,int B,int K){
    // code here
    long long int p = pow(A,B);
    string s = to_string(p);
    return s[s.length()-K]-'0';
}

//https://www.geeksforgeeks.org/problems/check-if-a-number-is-power-of-another-number5442/1?page=2&difficulty=Basic&status=unsolved&sortBy=submissions
int isPowerOfAnother(long long x, long long y){
        if ( x == 1 ) 
           return y == 1;
        while (!( y % x )) y /= x;
        return y == 1; 
 }
 //https://www.geeksforgeeks.org/problems/elements-in-the-range2834/1?page=4&difficulty=Basic&sortBy=submissions
 bool check_elements_are_in_range_A_B(int arr[], int n, int A, int B)
	{
	    unordered_set<int> count;
        for(int i=0;i<n;i++){
            if(arr[i]>=A && arr[i]<=B) count.insert(arr[i]);
        }
      
        for(int i=A;i<=B;i++) if(count.find(i)==count.end()) return false;
        return true;
	}
//https://www.geeksforgeeks.org/problems/series-ap5310/1?page=2&difficulty=School&sortBy=submissions
     int nthTermOfAP(int a1, int a2, int n) {
        return a1+(n-1)*(a2-a1);
    }
//https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1
    const long long int mod=1e9+7;
    vector<int> Series(int n) {
        // Code here
        long long int first=0,second=1,current;
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(second);
        for(int i=2;i<=n;i++)
        {
            current=(second%mod+first%mod)%mod;
            ans.push_back(current);
            first=second;
            second=current;
        }
        return ans;
    }
//https://www.geeksforgeeks.org/problems/product-of-primes5328/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
    const long long mod=1e9+7;
    long long primeProduct(long long L, long long R){
        // code here
        vector<bool> sieve=getSegmentedSieve(L,R);
        long long ans=1;
        for(int prime=0;prime<sieve.size();prime++)
        {
            if(sieve[prime]==true)
            {
                // cout<<prime+L<<" ";
                ans=(ans*((prime%mod+L%mod)%mod))%mod;
            }
        }
        return ans;
    }
    vector<bool> getSegmentedSieve(long long L,long long R)
    {
        vector<bool> basicSieve = getSieve(sqrt(R));
        vector<bool> segmentedSieve(R-L+1,true);
        if(L==0){
          segmentedSieve[L-1]=false;
          segmentedSieve[L]=false;
        }
        if(L==1){
          segmentedSieve[L-1]=false;
        }
        for(long long int prime=2;prime<basicSieve.size();prime++)
        {
            if(basicSieve[prime]==true){
                long long int firstMul =(L/prime)*prime;
                if(firstMul<L)
                  firstMul+=prime;
                long long int firstToBeMarked = max(prime*prime,firstMul);
                long long int j=firstToBeMarked-L;
                // cout<<prime<<" "<<firstToBeMarked<<" "<<j<<" -";
                while(j<R-L+1)
                {
                    segmentedSieve[j]=false;
                    j+=prime;
                    // cout<<"*"<<j<<" ";
                }
            }
        }
        // cout<<endl;
        // for(auto p:segmentedSieve)
        //  cout<<p<<" ";
        // cout<<endl;
        return segmentedSieve;
    }
    vector<bool> getSieve(long long n)
    {
        vector<bool> sieve(n+1,true);
        sieve[0]=sieve[1]=false;
        for(long long i=2;i*i<=n;i++)
        {
            if(sieve[i]==true)
            {
                long long j=i*i;
                while(j<=n)
                {
                    sieve[j]=false;
                    j+=i;
                }
            }
        }
        // for(auto e:sieve)
        //   cout<<e<<" ";
        // cout<<endl;
        return sieve;
    }
//https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1?page=8&difficulty=Easy&sortBy=submissions
long long sumOfDivisors(int N)//use contribution method ( contribution of a divisor 'i' in sum upto N numbers= (N/i)*i)
    {
       long long ans = 0;
        for(int i = 1; i<=N; i++) {
            ans += (N/i)*i;            //getting no. of times (frequency) of divisor of a number by N/i
        }
        return ans;
    }
//https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1
long long int PowMod(long long int x,long long int n,long long int M)
		{
		   long long int res=1;
		  
		   while(n>0)
		   {
		       if(n&1)
		         res=((res%M)*(x%M)%M);
		       
		       x=((x%M)*(x%M)%M);
		       n=n>>1;
		   }
		   return res%M;
		}
 int main()
{
    return 0;
}