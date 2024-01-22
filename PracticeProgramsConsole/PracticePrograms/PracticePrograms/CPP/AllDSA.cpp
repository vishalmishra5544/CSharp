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

int main()
{
	return 0;
}