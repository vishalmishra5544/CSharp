    #include<bits/stdc++.h>
    using namespace std;

    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<int> currPath;
        vector<vector<int>> ans;
        helperToGetAllPathsInTree(root,sum,0,currPath,ans);
        return ans;
    }
    
    void helperToGetAllPathsInTree(Node *root,int sum,int currSum,vector<int> &currPath,vector<vector<int>> &ans)
    {
        if(root==NULL)
         return;
        currSum+=root->key;
        currPath.push_back(root->key);
        if(currSum==sum)
        {
           ans.push_back(currPath);
        }
        helperToGetAllPathsInTree(root->left,sum,currSum,currPath,ans);
        helperToGetAllPathsInTree(root->right,sum,currSum,currPath,ans);
        currPath.pop_back();
    }
    vector<int> findPriorityOrder(int n, int m, vector<vector<int>> prerequisites) //{i,j}  task i needs j to be done first. //use Topological sort
    {
        //code here
        unordered_map<int,vector<int>> adjList;
        vector<int> inDegree(n,0);
        vector<int> ans;
        for(auto &ele:prerequisites)
        {
            adjList[ele[1]].push_back(ele[0]);
            inDegree[ele[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto &neighbour:adjList[top])
            {
                inDegree[neighbour]--;
                if(inDegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }
        
        if(ans.size()==n)
        {
            return ans;
        }
        else
         return {};
    }
int main()
{
	return 0;
}