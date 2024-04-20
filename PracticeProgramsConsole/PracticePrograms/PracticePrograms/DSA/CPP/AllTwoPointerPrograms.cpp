#include<bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1?page=2&sprint=94ade6723438d94ecf0c00c3937dad55&sortBy=submissions
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr,arr+N);
        int sum = 0;
        int i = N-1;
        while(i>0){
            if(arr[i] - arr[i-1] < K){
                sum = sum + arr[i] + arr[i-1];
                i = i-2;
                
            }
            else i--;
                
        }
        
        return sum;
      
    }
//https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
//arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    //Approach -1
    // vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    // {
    //     vector<int> ans;
    //     set<int> s;
    //     for(int i=0;i<n;i++)
    //       s.insert(arr1[i]);
    //     for(int i=0;i<m;i++)
    //     {
    //         if(s.find(arr2[i])==s.end())
    //           s.insert(arr2[i]);
    //     }
    //     for(auto &ele:s)
    //     {
    //         ans.push_back(ele);
    //     }
    //     return ans;
    // }
    //Approach -2
     //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i = 0, j = 0; 
        vector<int> ans;
        //Using two pointers i and j over the two arrays which helps
        //in storing the smaller element.
        while (i < n && j < m) 
        { 
            //Updating the pointer i until we have identical 
            //elements at consecutive position in arr1.
            while(  i+1<n  &&  arr1[i]==arr1[i+1]  )
                i++;
               
            //Updating the pointer j until we have identical 
            //elements at consecutive position in arr2.
            while(  j+1<m  &&  arr2[j]==arr2[j+1]  )
                j++;
                
        
            //Comparing element of the arrays arr1 and arr2 at pointers
            //i and j and accordingly storing the smaller element
            //and updating the pointers.
            if (arr1[i] < arr2[j]) 
                ans.push_back(arr1[i++]);
          
            else if (arr2[j] < arr1[i]) 
                ans.push_back(arr2[j++]);
                
            else
            {
                //If arr1[i] is same as arr2[j], we update both pointers.
                ans.push_back(arr1[i++]);
                j++;
            }
        } 
        
        //Storing the remaining elements of first array (if there are any).
        while(i < n)
        {
            //Updating the pointer i until we have identical 
            //elements at consecutive position in arr1.
            while(  i+1<n  &&  arr1[i]==arr1[i+1]  )
                i++;
            
            //Storing the elements.
            ans.push_back(arr1[i++]);
        }
        //Storing the remaining elements of second array (if there are any).
        while(j < m)
        {
            //Updating the pointer j until we have identical 
            //elements at consecutive position in arr2.
            while(  j+1<m  &&  arr2[j]==arr2[j+1]  )
                j++;
            
             //Storing the elements
            ans.push_back(arr2[j++]);
        }
        
        //returning the list containing the union of the two arrays. 
        return ans;
    }
int main()
{
	return 0;
}