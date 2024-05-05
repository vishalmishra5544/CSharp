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
 //https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
//m1-
//Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> ans;
        if(root==NULL)return ans;
        queue<Node*> q;
        q.push(root);
        ans.push_back(root->data);
        while(!q.empty()){
           int count=q.size();
           while(count>0){
               Node* curr=q.front();
               q.pop();
               if(curr->left){ ans.push_back(curr->left->data);q.push(curr->left);}
               else ans.push_back(-100);
               if(curr->right){ ans.push_back(curr->right->data);q.push(curr->right);}
               else ans.push_back(-100);
               count--;
           }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if(A.size()==0)return NULL;
       int i=0;
       Node* root=new Node(A[i]);
       queue<Node*>q;
       q.push(root);
       i++;
       while(!q.empty()){
           int count=q.size();
           while(count>0){
               Node* curr=q.front();
               q.pop();
               if(A[i]!=-100){Node* n=new Node(A[i]);curr->left=n;q.push(n);}
               //else curr->left=NULL;
               i++;
               if(A[i]!=-100){curr->right=new Node(A[i]);q.push(curr->right);}
               //else curr->right=NULL;
               i++;
               count--;
           }
       }
       return root;
    }
//m2-
  //Function to store the nodes of tree in the list.
    void serializeUtil(Node*root, vector<int>&a)
    {
        //base case if node is null.
        if (root == NULL) {
            a.push_back(-1);
            return;
        }
        //storing the data at node in list.
        a.push_back(root->data);
        
        //calling function recursively for left and right subtrees.
        serializeUtil(root->left, a);
        serializeUtil(root->right, a);
    }
    
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> serialized;
        serializeUtil(root,serialized);
        
        //returning the list.
        return serialized;
    }
    
    
    //Function to construct the tree.
    Node *kewl(vector<int> &a, int *index) 
    {
        //base case if there are no more elements in list.
        if (*index == a.size() or a[*index] == -1) {
            *index += 1;
            return NULL;
        }
        
        //creating new node for storing current element.
        Node *root = new Node(a[*index]);
        *index += 1;
        
        //calling function recursively for left and right subtrees. 
        root->left = kewl(a, index);
        root->right = kewl(a, index);
        return root;
    }
    
    //Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &a) 
    {
        int index = 0;
        //returning the tree.
        return kewl(a, &index);
    }
//https://www.geeksforgeeks.org/problems/k-distance-from-root/1
 // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
       queue<Node*> q;
       q.push(root);
       int size;
       vector<int> ans;
       while(!q.empty()&&k>=0)
       {
           size=q.size();
           while(size--)
           {
               Node* front=q.front();
               q.pop();
               if(k==0)
                    ans.push_back(front->data);
               if(front->left)
                   q.push(front->left);
               
               if(front->right)
                q.push(front->right);
           }
           k--;
       }
       return ans;
    }
 //https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
 //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
     // Base case: If no nodes, return nullptr
        if (n == 0) {
            return nullptr;
        }

        // Find the root node index in inorder traversal
        int rootIndex = 0;
        while (rootIndex < n && in[rootIndex] != post[n - 1]) {
            rootIndex++;
        }

        // Create the root node with the value from postorder traversal
        Node* root = new Node(post[n - 1]);

        // Recursively build left subtree using elements before root in inorder traversal
        root->left = buildTree(in, post, rootIndex);

        // Recursively build right subtree using elements after root in inorder traversal
        root->right = buildTree(in + rootIndex + 1, post + rootIndex, n - rootIndex - 1);
        

        return root;    
    }
//https://www.geeksforgeeks.org/problems/vertical-sum/1
vector <int> verticalSum(Node *root) {
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> h;
        vector<int> ans;
        while(!q.empty())
        {
            auto front=q.front();
            q.pop();
            h[front.second]+=front.first->data;
            if(front.first->left)
            {
                q.push({front.first->left,front.second-1});
            }
            if(front.first->right)
            {
                q.push({front.first->right,front.second+1});
            }
        }
        for(auto &ele:h)
          ans.push_back(ele.second);
        return ans;
        
    }
int main()
{
	return 0;
}