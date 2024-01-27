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

int main()
{
    string ans =findSum("25","23");
    cout<<ans;
}