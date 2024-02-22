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

//Remove All adjacent duplicates (only 2)
string removeAdjacentDuplicatesAtMax2(string s)
{
    string ans="";
    for(int i=0;i<s.length();i++)
    {
        if(ans.length()>0 && s[i]==ans[ans.length()-1])
        {
            ans.pop_back();
        }
        else{
            ans.push_back();
        }
    }
    return ans;
}
//Recursively remove all adjacent duplicates (more than 2)
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

//https://www.geeksforgeeks.org/problems/game-with-string4100/1
int minValue(string s, int k){
        // code here
        int freq[26]={0};
        for(auto& ele:s)
        {
            freq[ele-'a']++;
        }
        sort(freq,freq+26);
        for(int i=0;i<k;i++)
        {
            freq[25]--;
            sort(freq,freq+26);
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            ans+=(freq[i]*freq[i]);
        }
        return ans;
    }
//Remove all occurrence of substring
//using find();
// string removeAllOccurreneOfSubstring(string s,string part)
// {
//     int pos=s.find(part);
//     while(pos!=string::npos)
//     {
//         s.erase(pos,part.length());
//         pos = s.find(part);
//     }
//     return s;
// }
//w/o using find()  https://www.geeksforgeeks.org/minimize-a-string-by-removing-all-occurrences-of-another-string/
// Function to find the minimum length
// to which string str can be reduced to
// by removing all occurrences of string K
int removeAllOccurreneOfSubstring(string str, int N,
              string K, int M)
{
 
    // Initialize stack of characters
    stack<char> stackOfChar;
 
    for (int i = 0; i < N; i++) {
 
        // Push character into the stack
        stackOfChar.push(str[i]);
 
        // If stack size >= K.size()
        if (stackOfChar.size() >= M) {
 
            // Create empty string to
            // store characters of stack
            string l = "";
 
            // Traverse the string K in reverse
            for (int j = M - 1; j >= 0; j--) {
 
                // If any of the characters
                // differ, it means that K
                // is not present in the stack
                if (K[j] != stackOfChar.top()) {
 
                    // Push the elements
                    // back into the stack
                    int f = 0;
                    while (f != l.size()) {
 
                        stackOfChar.push(l[f]);
                        f++;
                    }
 
                    break;
                }
 
                // Store the string
                else {
 
                    l = stackOfChar.top()
                        + l;
 
                    // Remove top element
                    stackOfChar.pop();
                }
            }
        }
    }
 
    // Size of stack gives the
    // minimized length of str
    return stackOfChar.size();
}

// VALID PALINDROME -2  https://www.geeksforgeeks.org/remove-character-string-make-palindrome/
// This method returns -1 if it is not possible to make string
// a palindrome. It returns -2 if string is already a palindrome.
// Otherwise it returns index of character whose removal can
// make the whole string palindrome.
int possiblePalinByRemovingOneChar(string str)
{
    //  Initialize low and high by both the ends of the string
    int low = 0, high = str.length() - 1;
 
    //  loop until low and high cross each other
    while (low < high)
    {
        // If both characters are equal then move both pointer
        // towards end
        if (str[low] == str[high])
        {
            low++;
            high--;
        }
        else
        {
            /*  If removing str[low] makes the whole string palindrome.
                We basically check if substring str[low+1..high] is
                palindrome or not. */
            if (isPalindrome(str.begin() + low + 1, str.begin() + high))
                return low;
 
            /*  If removing str[high] makes the whole string palindrome
                We basically check if substring str[low+1..high] is
                palindrome or not. */
            if (isPalindrome(str.begin() + low, str.begin() + high - 1))
                return high;
 
            return -1;
        }
    }
 
    //  We reach here when complete string will be palindrome
    //  if complete string is palindrome then return mid character
    return -2;
}

//https://leetcode.com/problems/minimum-time-difference/
int findMinDifference(vector<string>& timePoints) {
        vector<int> time(timePoints.size(),0);
        int hrs,minutes,i=0,n=timePoints.size();
        for(auto &ele:timePoints)
        {
            hrs=stoi(ele.substr(0,2));
            minutes=stoi(ele.substr(3,2));
            time[i++]=(hrs*60)+minutes;           
        }
        sort(time.begin(),time.end());        
        int minDiff=INT_MAX;
        for(int j=0;j<n-1;j++)
        {
            minDiff=min(minDiff,(time[j+1]-time[j]));//compare neighbours for min diff
        }

        int specialDiff1=time[n-1]-time[0]; //for cases like: 00:00 interpreted as 00:00
        minDiff=min(minDiff,specialDiff1);
        int specialDiff2=time[0]+(24*60)-time[n-1]; //for cases like: 00:00 interpreted as 24:00 and compared with 23:59
        minDiff=min(minDiff,specialDiff2);
        return minDiff;
    }

//https://leetcode.com/problems/palindromic-substrings/
int countPalindromicSubstringsInString(string s) {
        int count=0;
        int i=0,j=0,n=s.length();
        for(int k=0;k<n;k++)//odd length substrings check
        {
            i=k;
            j=k;
            while(i>=0&&j<=n-1)
            {
                if(s[i]==s[j])//if it is palindrome then expand
                {
                    count++;
                    i--;
                    j++;
                }
                else//else start from next start position
                {
                    break;
                }
            }
        }
        for(int k=0;k<n-1;k++)//even length substrings check
        {
            i=k;
            j=k+1;
            while(i>=0&&j<=n-1)
            {
                if(s[i]==s[j])//if it is palindrome then expand
                {
                    count++;
                    i--;
                    j++;
                }
                else//else start from next start position
                {
                  break;
                }
            }
        }
        return count;
    }
int main()
{
	return 0;
}