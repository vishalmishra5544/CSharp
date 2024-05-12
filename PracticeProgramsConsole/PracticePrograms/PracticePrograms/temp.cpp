#include<bits/stdc++.h>
using namespace std;
    bool static cmp(vector<int> &a,vector<int> &b)
    {
       return sqrt((a[0]*a[0]) + (a[1]*a[1]))<sqrt((b[0]*b[0]) + (b[1]*b[1]));  
    }
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        
        int size=0,ans=0,mini=INT_MAX,maxi=INT_MIN;
        bool found=false;
        unordered_set<char> h;
        unordered_map<int,vector<pair<int,char>>> h1;
        for(int j=0;j<points.size();j++)
        {
            int e=max(abs(points[j][0]),abs(points[j][1]));
            maxi=max(maxi,e);
            mini=min(mini,e);
            h1[e].push_back({j,s[j]});
        }
        size=mini;
        //sort(points.begin(),points.end(),cmp);
        // for(auto &e:points)
        //     cout<<e[0]<<" "<<e[1]<<" ,";
        while(size<=maxi)
        {
            while(h1.find(size)==h1.end())
                size++;
            auto ele = h1[size++];
            int curr=0;
            for(auto &e:ele)
            {                
                if(h.find(e.second)==h.end())
                {                    
                    h.insert(e.second);                      
                      curr++;
                }
                else{
                    found=true;
                    break;
                }
                
            }
            if(!found)
            {
                ans+=curr;
            }
            found=false;
        }
        
        return ans;
    }
int main()
{
    vector<vector<int>> v;
    v.push_back({2,2});
    v.push_back({-1,-2});
    v.push_back({-4,4});
    v.push_back({-3,1});
    v.push_back({3,-3});
    string s="abdca";
    cout<<maxPointsInsideSquare(v,s);

}