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
 int main()
{
    return 0;
}