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
int main()
{
	return 0;
}