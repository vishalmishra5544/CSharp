#include<bits/stdc++.h>
using namespace std;
bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int curr,left,right;
        for (int i = 0; i < (n / 2) ; i++) {
            // Check left child
            if (arr[i] < arr[2 * i + 1]) {
                return false;
            }
            // Check right child
            if (arr[i] < arr[2 * i + 2]) {
                return false;
            }
        }
        return true;
    }
int main()
{
	return 0;
}