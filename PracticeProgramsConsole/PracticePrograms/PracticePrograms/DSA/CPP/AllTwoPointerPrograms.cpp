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
int main()
{
	return 0;
}