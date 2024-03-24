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

class twoStacks
{
    public:
    int *arr=NULL;
    int top1,top2;
    int size;
    twoStacks()
    {
        arr = new int[100];
        size=100;
        top1=-1;
        top2=100;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        top1++;
        if(top1==size || top1>=top2)
          return;
        arr[top1]=x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        top2--;
        if(top2==0 || top2<=top1)
          return;
        arr[top2]=x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1<0)
         return -1;
        int ans = arr[top1];
        top1--;
        return ans;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2==100)
         return -1;
        int ans = arr[top2];
        top2++;
        return ans;
    }
};
//https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1
stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> st1;
        while(!st.empty())
        {
           st1.push(st.top());
           st.pop();
        }
        st.push(x);
        while(!st1.empty())
        {
            st.push(st1.top());
            st1.pop();
        }
        return st;
    }
    int main()
    {
        return 0;
    }