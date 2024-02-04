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
int main()
{
	return 0;
}