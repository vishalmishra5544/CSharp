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
 int main()
{
    return 0;
}