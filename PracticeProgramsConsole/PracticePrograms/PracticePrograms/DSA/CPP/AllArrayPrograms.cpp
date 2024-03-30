#include<bits/stdc++.h>
using namespace std;
string findSum(string X, string Y) {
        // Your code goes here
        int carry=0;
        int i=X.size()-1,j=Y.size()-1;
        string ans="";
        int sum=0;
        while(i>=0 && j>=0)
        {
            sum = (X[i]-'0') + (Y[j]-'0')+carry;
            carry = sum/10;
            ans+=(char((sum%10) + '0'));
            i--;j--;
        }
                //cout<<ans;
        while(i>=0)
        {
            sum = (X[i]-'0')+carry;
            carry = sum/10;
            ans+=(char((sum%10) + '0'));
            i--;   
        }
                //cout<<ans;
        while(j>=0)
        {
            sum = (Y[j]-'0')+carry;
            carry = sum/10;
            ans+=(char((sum%10) + '0'));
            j--;
        }
        while(carry)
        {
            ans+=(char((carry%10)+'0'));
            carry/=10;
        }
        //cout<<ans;
        i=ans.size()-1;
        while(i>=1 && ans[i--]=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    int smallestSubWithSum(int a[], int n, int x)
    {
        int ans=0;
        int sum=0;
        int maxSum=0;
        
        int start=0;
        
        int minLength = n+1;
        
        for(int i=0;i<n;i++){
            
            sum+=a[i];
            
            if(sum>x){  //is sum is greater then X then subtract sum
            
                while(sum>x){
                    sum-=a[start++];
                }
                minLength = min(minLength,i-start+2);
                
            } 
        }
        return minLength ==n+1?0:minLength;
    }
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq;//will store index of  max of window in front
        for(int i=0;i<k;i++){//first window
            while(!dq.empty()&&arr[i]>=arr[dq.back()]){//remove all small elements compared to ith ele from right
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k;i<n;i++){//remaining windows
            ans.push_back(arr[dq.front()]);//ans of previous window
            while(!dq.empty()&&dq.front()<=i-k){dq.pop_front();}//remove all small elements compared to ith ele from right
            while(!dq.empty()&&arr[i]>=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);//ans of last window
        return ans;
    }

    public int firstElementKTime(int n, int k, int[] a)
    {
        if(k==1)
        {
            return n>0?a[0]:-1;
        }
        Dictionary<int,int> d = new Dictionary<int,int>();
        foreach(var ele in a)
        {
            if(d.ContainsKey(ele))
            {
              d[ele]++;
              if(d[ele]==k)
                return ele;
            }
            else 
              d.Add(ele,1);
        }
        return -1;
    }
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        int i=0,start=0;
        long int sum=0,maxi=INT_MIN;
        for(i=0;i<k;i++)
        {
            sum+=arr[i];
        }
        maxi=max(maxi,sum);
        while(i<n)
        {
            sum-=arr[start++];
            sum+=arr[i++];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
    long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long prefix = 1;
        long long sufix = 1;
        long long ans = INT_MIN;
        for(int i=0; i<n; i++){
            prefix = prefix * arr[i];
            sufix = sufix * arr[n-i-1];
            ans = max(ans,max(prefix,sufix));
             if(prefix == 0){
                prefix = 1;
            }
            if(sufix == 0){
                sufix = 1;
            }
        }
        return ans;
	}
//https://www.geeksforgeeks.org/problems/unsorted-array4925/1?page=1&difficulty=Easy&status=unsolved&sortBy=submissions
    int findElement(int arr[], int n) {
    vector<int> greater(n,arr[n-1]);
    for(int i=n-2; i>=0; i--)
        greater[i] = min(greater[i+1], arr[i]);
    for(int i=1; i<n-1; i++) {
        if(arr[i] >= arr[i-1] && arr[i] <= greater[i+1])
            return arr[i];
        arr[i] = max(arr[i-1], arr[i]);
    }
    return -1;
}
//https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1?page=4&category=Arrays&sprint=94ade6723438d94ecf0c00c3937dad55&sortBy=submissions
int smallestSumSubarray(vector<int>& a){
      for(auto &ele:a)
       ele=ele*(-1);
      int currSum=0,ans=INT_MIN;
      for(int i=0;i<a.size();i++)
      {
          currSum+=a[i];
          ans=max(ans,currSum);
          if(currSum<0)
            currSum=0;
      }
      return ans*(-1);
  }
int main()
{
    string ans =findSum("25","23");
    cout<<ans;
}