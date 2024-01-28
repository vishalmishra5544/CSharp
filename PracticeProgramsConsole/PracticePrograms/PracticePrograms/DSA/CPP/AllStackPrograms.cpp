#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='[' || x[i]=='(' || x[i]=='{')
            {
                st.push(x[i]);
            }
            else
            {
                if(st.size()==0)
                 return false;
                if((x[i]==']' and st.top()!='[' )||(x[i]=='}' and st.top()!='{' )||(x[i]==')' and st.top()!='('))
                {
                    return false;
                }
                else 
                {
                    st.pop();
                }
            }
        }
        if(st.size()>0)
         return false;
        return true;
    }

    int main()
    {
        return 0;
    }