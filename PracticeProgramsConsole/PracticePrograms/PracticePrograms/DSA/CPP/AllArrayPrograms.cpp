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
int main()
{
    string ans =findSum("25","23");
    cout<<ans;
}