#include<bits/stdc++.h>
using namespace std;

public:
	int TotalPairs(vector<int>nums, int k){
	    // Code here
	    //using 2 pointer + sliding window
	   // sort(nums.begin(),nums.end());
        //     int s=0,e=1;
        //     set<pair<int,int>> totalPairs;
        //     while(s<e && e<nums.size())
        //     {
        //         int diff=nums[e]-nums[s];
        //         if(diff==k)
        //         {
        //             totalPairs.insert(make_pair(nums[s],nums[e]));
        //             s++;e++;
        //         }
        //         else if(diff>k)
        //         {
        //             s++;
        //         }
        //         else
        //         {
        //             e++;
        //         }
        //         if(s==e)
        //           e++;
        //     }
        //     return (int)totalPairs.size();
        
    
        //using binary search
        set<pair<int,int>> totalPairs;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size())
        {
             int j = binarySearch(nums,i+1,nums.size()-1,k+nums[i]); //nums[j]-nums[i]==k  =>nums[j]=k+nums[i] and we need to find nums[j] is there of not => search for k+nums[i] in right from j to end;
             if(j!=-1)
              totalPairs.insert({nums[i],nums[j]});
             i++;
        }
        return totalPairs.size();
	}
    
    int binarySearch(vector<int> &nums,int s,int e,int key)
    {
        int mid=0;
        while(s<=e)
        {
            mid = s+(e-s)/2;
            if(nums[mid]==key)
            {
                return mid;
            }
            if(nums[mid]>key)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return -1;
    }

vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        //using 2 pointer  (outside to inside window length minimization)
        // int s=0,e=n-1;
        // while((e-s)>k)
        // {
        //     if((abs(x-arr[s]))>=(abs(arr[e]-x)))
        //     {
        //         s++;
        //     }
        //     else
        //     {
        //         e--;
        //     }
        // }
        // vector<int> ans;
        // while(s<=e)
        // {
        //     ans.push_back(arr[s]);
        //     s++;
        // }
        // return ans;
        
        //using binary search  (inside to outside window length maximization)
        int ind=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i=ind-1,j=ind+1;
        vector<int>ans;
        if(arr[ind]!=x){
            i=ind-1;
            j=ind;
        }
        while(k--){
            int diffL=INT_MAX,diffR=INT_MAX;
            if(i>=0){
                diffL=abs(x-arr[i]);
            }
            if(j<n){
                diffR=abs(arr[j]-x);
            }
            if(diffL<diffR){
                ans.push_back(arr[i]);
                i--;
            }
            else{
                ans.push_back(arr[j]);
                j++;
            }
        }
        return ans;
        
    }

    int transitionPoint(int arr[], int n) {
        // code here
        if(binary_search(arr,arr+n,1))
           return lower_bound(arr,arr+n,1)-arr;
        return -1;
    }

    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) //we minimize the maximum noOfPages continuously read.
    {
        //code here
        if(M>N)
          return -1;
        int start=0,end=0,mid,ans=-1;
        for(int i=0;i<N;i++)
        {
            end+=A[i];
        }
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(isPossibleToAllocateBooks(A,N,M,mid))
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;
    }
    bool isPossibleToAllocateBooks(int A[],int N,int M,int atMaxPages)
    {
        
        int noOfStudents=1;//first student, we require at least 1  student to start with reading first
        long long totalPages=0;//total pages read
        for(int i=0;i<N;i++)
        {
            if(A[i]>atMaxPages)
             return false;
           
            if(totalPages+A[i]>atMaxPages)
            {
                totalPages=A[i];
                noOfStudents++;
                if(noOfStudents>M)
                  return false;
            }
            else
            {
                 totalPages+=A[i];
            }
            
        }
        return true;
    }

long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        //sort(arr,arr+n);
        long long start=0,end=0,mid,ans=-1;
        for(int i=0;i<n;i++)
         end+=arr[i];
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(isPossibleToPaint(arr,n,k,mid))
            {
                ans = mid;
                end=mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;
    }
    bool isPossibleToPaint(int arr[],int n,int k ,long long mid)
    {
        long long currLen=0,noOfWorkers=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
             return false;
            if(currLen + arr[i] >mid)
            {
                currLen=arr[i];
                noOfWorkers++;
                if(noOfWorkers>k)
                 return false;
            }
            else
            {
              currLen+=arr[i];
                
            }
        }
        return true;
    }

    int maxHeight(vector<int>&A, int M){
        //Write your code here
        int start=0,end=INT_MIN,mid=0,ans=-1;
        for(auto &ele:A)
        {
            end=max(end,ele);
        }
        while(start<=end)
        {
            mid = start+(end-start)/2;
            if(isPossibleToCut(A,M,mid))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
    bool isPossibleToCut(vector<int>&A,int M,int atMaxHeight)
    {
        long long totalWood=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>atMaxHeight)
              totalWood += (A[i]-atMaxHeight);
        }
        if(totalWood>=M)
         return true;
        else
         return false;
    }
int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());//sort because here in input there is non sorted positons of stalls but we need sorted as these are positions on numberline
        int start=0,end=0,mid=0,ans=-1;
        end=stalls[n-1]-stalls[0];
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(isPossibleToPlaceCows(n,k,stalls,mid))
            {
                ans=mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return ans;
    }
    
    bool isPossibleToPlaceCows(int n,int k,vector<int> &stalls,int atMinDistance)
    {
        int noOfCowsPlaced=1;//first cow, require at least 1 cow to place first
        int lastStallPosition=stalls[0];//first cow will be placed at 1st stall
        for(int i=1;i<n;i++)//start from 2nd stall
        {
            if(stalls[i]-lastStallPosition>=atMinDistance)
            {
                noOfCowsPlaced++;
                if(noOfCowsPlaced==k)
                  return true;
                lastStallPosition=stalls[i];
            }
        }
         
        return false;
    }

    include <bits/stdc++.h>
using namespace std;
 

 
// Function to find the minimum time required
// to fulfill the orders
int findMinTime(int n, vector<int>& cooks, int l)
{
    // write your code here
    int s = 0, highestRank = *max_element(cooks.begin(),cooks.end()),e=highestRank*(n*(n+1)/2); //end time is sum of 1R+2R+...+nR for most time taking cook i.e rank highest
    int mid, ans = -1;
 
    // Loop to implement binary search
    while (s <= e) {
        mid = (s + e) / 2;
        if (isPossibleToCookPratas(n, cooks, l, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
 
    return ans;
}
// Function to check if it is possible
// to fulfill N orders in 'mid' time
bool isPossibleToCookPratas(int reqdNoOfPratas, vector<int>& cook, int n, int atMaxMinutes)
{
    int noOfPratasCooked = 0;
    for (int i = 0; i < n; i++) {
 
        // For each cook count the pratas
        int R = cook[i];
        int j = 1;// counter for 1R + 2R +...jR
        int timeTaken = 0;//for this cook as all can do it in parallel hence time start from 0
 
        
        while (true) {
            if(timeTaken + j*R<=atMaxMinutes )
            {
                noOfPratasCooked++;
                timeTaken+=j*R;
                j++;
            }
            else
            {
                break;
            }
        }
        
        if (noOfPratasCooked >= reqdNoOfPratas)
            return true;
    }
 
    return false;
}
//https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1?page=6&difficulty=Easy&sortBy=submissions
int findMin(int a[], int n){
        //complete the function here
        int start = 0;
        int end= n-1;
        int mid=0;
      
        while( start+1 < end){
            mid = (start+end)/2;
            if((a[start] < a[mid])&& (a[end] < a [mid])){
             
                 start = mid;
          
            }else{
                end=mid;
            }
        }
      if( a[start] < a[end]){
          mid = start;
      }else{
          mid= end;
      }
     return a[mid];
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
int main()
{
	return 0;
}