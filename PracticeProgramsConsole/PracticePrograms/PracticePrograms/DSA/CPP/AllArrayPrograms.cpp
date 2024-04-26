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

  //https://www.geeksforgeeks.org/problems/reverse-bits3556/1
long long reversedBits(long long x) {
        // code here
        vector<int>  arr(32,0);
        int end=31;
        while(x>0)
        {
            if(x%2==0)
              arr[end]=0;
            else
              arr[end]=1;
            x/=2;
            end--;
        }
        long long int ans=0;
        for(int i=31;i>=0;i--)
        {
           //cout<<arr[i]<<" ";
           ans+=(arr[i]*pow(2,i));
            
        }
        return ans;
    }
//https://www.geeksforgeeks.org/problems/minimize-the-difference/1
int minimizeDifference(int n, int k, vector<int>& arr) {
        // Arrays to store maximum and minimum elements from a certain position
        vector<int> post_max(n);
        vector<int> post_min(n);

        // Initializing the maximum and minimum elements from the last position
        post_min[n - 1] = arr[n - 1];
        post_max[n - 1] = arr[n - 1];

        // Loop to update the maximum and minimum elements from each position
        for (int i = n - 2; i >= 0; --i) {
            post_max[i] = max(arr[i], post_max[i + 1]);
            post_min[i] = min(arr[i], post_min[i + 1]);
        }

        // Initializing the minimum difference with elements at k
        int min_diff = post_max[k] - post_min[k];

        // Initializing variables to keep track of current minimum and maximum elements
        int p_min = arr[0];
        int p_max = arr[0];

        // Loop to update the minimum difference by considering each window of size k
        for (int i = 1; i < n - k; ++i) {
            int curr_min = max(p_max, post_max[i + k]) - min(p_min, post_min[i + k]);
            min_diff = min(min_diff, curr_min);
            p_max = max(arr[i], p_max);
            p_min = min(arr[i], p_min);
        }

        // Updating the minimum difference considering the remaining elements
        min_diff = min(min_diff, p_max - p_min);

        // Returning the final minimized difference
        return min_diff;
    }
//https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1
//Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
         int maxi = n+1;
        vector<int> ans;

        for(int i = 0;i<n+2;i++){
            
            int ind = arr[i]%maxi;
            
            arr[ind-1] += maxi;
            
            if((arr[ind-1]/maxi)==2)
                ans.push_back(ind);
            
        }

        return ans;
    }
//https://www.geeksforgeeks.org/problems/in-first-but-second5423/1
vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    unordered_set<int> h;
	    vector<int> ans;
	    for(int i=0;i<m;i++)
	      h.insert(b[i]);
	    for(int i=0;i<n;i++)
	    {
	        if(h.find(a[i])==h.end())
	        {
	            ans.push_back(a[i]);
	        }
	    }
	    return ans;
	} 
//https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1
int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int minInd=INT_MAX,mini=INT_MAX,currSum=0;
        for(int i=0;i<n;i++)
        {
            currSum=0;
            for(int j=0;j<m;j++)
              currSum+=a[i][j];
            if(mini>currSum)
            {
                mini=currSum;
                minInd=i;
            }
            //cout<<i<<" "<<mini<<endl;
        }
        return minInd+1;
    }
//https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1
//find a^n  nd return a10 where a=[1 1]
                                  [1 0]
int firstElement(int n) {
        int a = 0, b = 1, c, i;
        for (i = 2; i <= n; i++) {
            c = a + b;
            a = b%1000000007;//using mod to not hit the max of int 
            b = c%1000000007;
        }
        return b;
    }
//https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1
int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=m-3;j++)
            {
                sum=mat[i][j]+mat[i][j+1]+mat[i][j+2]+mat[i+1][j+1]+mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2];
                maxi=max(maxi,sum);
            }
        }
        return maxi==INT_MIN?-1:maxi;
    }
//https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1
vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        char dir='R';
        int i=0,j=0;
        while(i>=0&&i<n&&j>=0&&j<m)
        {
           // cout<<matrix[i][j]<<" "<<i<<" "<<j<<endl;
            if(matrix[i][j]==1)
            {
                matrix[i][j]=0;
                switch(dir)
                {
                    case 'R':
                       dir='D';
                       i++;
                       break;
                    case 'L':
                       dir='U';
                       i--;
                       break;
                    case 'U':
                       dir='R';
                       j++;
                       break;
                    case 'D':
                       dir='L';
                       j--;
                       break;
                }
                
            }
            else
            {
                switch(dir)
                {
                    case 'R':
                       j++;
                       break;
                    case 'L':
                       j--;
                       break;
                    case 'U':
                       i--;
                       break;
                    case 'D':
                       i++;
                       break;
                }
            }
            
        }
        
        switch(dir)
        {
            case 'R':
               j=j-1;
               break;
            case 'L':
               j=j+1;
               break;
            case 'U':
               i=i+1;
               break;
            case 'D':
               i=i-1;
               break;
        }
        return {i,j};
    }
int main()
{
    string ans =findSum("25","23");
    cout<<ans;
}