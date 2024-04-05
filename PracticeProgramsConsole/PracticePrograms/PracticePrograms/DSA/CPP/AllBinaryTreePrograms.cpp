#include<bits/stdc++.h>
using namespace std;
//Function to return the level order traversal of a tree.
vector<int> levelOrder(Node* root)
{
    //Your code here
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        while(size-->0)
        {
            Node* front = q.front();
            ans.push_back(front->data);
            q.pop();
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);
        }
    }
    return ans;
}

 void preorder(Node *root,int sum,int& maxi,int noOfNodes,int & maxNoOfNodes)
    {
        if(root==NULL)
        {
            if(maxNoOfNodes<noOfNodes)
            {
                maxNoOfNodes=noOfNodes;
                maxi=sum;
            }
            else if(maxNoOfNodes==noOfNodes)
            {
                maxi=max(maxi,sum);
            }
            return;
        }
        sum+=root->data;
        noOfNodes+=1;
        preorder(root->left,sum,maxi,noOfNodes,maxNoOfNodes);
        preorder(root->right,sum,maxi,noOfNodes,maxNoOfNodes);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum=0, maxi=0,noOfNodes=0,maxNoOfNodes=0;
        preorder(root,sum,maxi,noOfNodes,maxNoOfNodes);
        return maxi;
        
    }
 //https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
 vector <int> zigZagTraversal(Node* root)
    {
    	queue<Node*> q;
    	q.push(root);
    	vector<int> ans,level;
    	int odd=true;
    	while(!q.empty())
    	{
    	    int size=q.size();
    	    level.clear();
    	    while(size-->0)
    	    {
    	        Node* front = q.front();
    	        level.push_back(front->data);
    	        q.pop();
    	        if(front->left)
    	          q.push(front->left);
    	        if(front->right)
    	          q.push(front->right);
    	    }
    	    if(odd)
    	    {
    	        for(int i=0;i<level.size();i++)
    	        {
    	            ans.push_back(level[i]);
    	        }
    	        odd=false;
    	    }else{
    	        
    	        for(int i=level.size()-1;i>=0;i--)
    	        {
    	            ans.push_back(level[i]);
    	        }
    	        odd=true;
    	    }
    	}
    	return ans;
    }

vector<int> diagonalSum(Node* root) {
        // Add your code here
        queue<Node*>q;
        vector<int>v;
        q.push(root);
        while(!q.empty())
        {
            Node*ptr;
            int sum=0,n=q.size();
            for(int i=0;i<n;i++)
            {
                ptr=q.front();
                q.pop();
                while(ptr!=NULL)
                {
                    sum+=ptr->data;
                    if(ptr->left)
                    {
                        q.push(ptr->left);
                    }
                    ptr=ptr->right;
                }
            }
            v.push_back(sum);
        }
        return v;
    }
//https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1
int findMaxForN(Node* root, int n) {
        int ans=INT_MIN;
        searchClosestNeighbourInBST(root,n,ans);
        return ans==INT_MIN?-1:ans;
    }
    void searchClosestNeighbourInBST(Node* root,int& n,int& ans)
    {
        if(root==NULL)
         return;
        if(root->key==n)
        {
          ans=root->key;
          return;
        }
        if(root->key<n)
        {
          ans=max(ans,root->key);
          searchClosestNeighbourInBST(root->right,n,ans);
        }
        else
         searchClosestNeighbourInBST(root->left,n,ans);
    }
//https://www.geeksforgeeks.org/problems/leaf-under-budget/1?page=2&difficulty=Easy&status=unsolved&sortBy=submissions
int getCount(Node *root, int k) {
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        int cnt = 0;

        while (!q.empty() && k > 0) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (!node->left && !node->right) {
                if (level > k)
                    return cnt;

                ++cnt;
                k -= level;
            } else {
                if (node->left)
                    q.push({node->left, level + 1});
                if (node->right)
                    q.push({node->right, level + 1});
            }
        }

        return cnt;
    }
int main()
{
	return 0;
}