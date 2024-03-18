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
int main()
{
	return 0;
}