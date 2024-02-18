#include<bits/stdc++.h>
using namespace std;
string removeSpaces (string s)
    {
        //code here.
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
              ans+=s[i];
        }
        return ans;
    }


//Recursively remove all adjacent duplicates
string rremove(string s){
        // code here
        string s1=s;
        string s2;
        while(s1.length()!=s2.length())
        {
            s2=s1;
            s1=removeAdjacentDuplicates(s1);
        }
        return s1;
    }
string removeAdjacentDuplicates(string s){
     string ans="";
     
     for(int i=0;i<s.length();i++)
     {
         if(i+1<s.length() && s[i]==s[i+1])
         {
             while(i+1<s.length() && s[i]==s[i+1])
             {
                 i++;
             }
         }
         else
         {
             ans.push_back(s[i]);
         }
     }
     return ans;        
}

int main()
{
	return 0;
}