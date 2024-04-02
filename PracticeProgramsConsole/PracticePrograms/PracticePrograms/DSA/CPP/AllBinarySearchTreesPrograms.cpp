#include<bits/stdc++.h>
using namespace std;
Node *flattenBST(Node *root)
    {
        // code here
        Node * tempHead=new Node(0);
        helperToFlattenBST(root,tempHead);
        return tempHead->right;
    }
    Node* helperToFlattenBST(Node *root,Node* tempHead)
    {
        if(root==NULL)
         return tempHead;
        Node*left=root->left;
        Node*right=root->right;
        root->left=root->right=NULL;
        helperToFlattenBST(left,tempHead)->right=root;
        return helperToFlattenBST(right,root);
    }
//https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1
int ans=0;
    int merge(vector<int> &vec,int low,int mid,int high){
        vector<int> temp(high-low+1);
        int i=low;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=high){
            if(vec[i]<=vec[j]){
                temp[k++]=vec[i++];
            }else{
                ans+=mid-i+1;
                temp[k++]=vec[j++];
            }
        }
        while(i<=mid){
            temp[k++]=vec[i++];
        }
        while(j<=high){
            temp[k++]=vec[j++];
        }
        i=0;
        for(i=0;i<temp.size();i++){
            vec[i+low]=temp[i];
        }

        return ans;
    }
    
    int mergeSort(vector<int> &vec,int low,int high){
        if(low<high){
            int mid=(low+high)/2;
            mergeSort(vec,low,mid);
            mergeSort(vec,mid+1,high);
            merge(vec,low,mid,high);
        }
    }
    
    void inorder(Node* root,vector<int> &vec){
        if(!root) return;
        inorder(root->left,vec);
        vec.push_back(root->data);
        inorder(root->right,vec);
    }
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        vector<int> vec;
        inorder(root,vec);
        int ans=0;
        ans=mergeSort(vec,0,vec.size()-1);
        return ans;
    }
//https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1
 void solve(Node* root,long long int &last_node,long long int &diff){
        if (!root) return;
        solve(root->left, last_node, diff);
        diff = min(diff, abs(root->data - last_node));
        last_node = root->data;
        solve(root->right, last_node, diff);
    }
    int absolute_diff(Node *root)
    {
        long long int diff = INT_MAX;
        long long int last_node = INT_MIN;
        long long int temp_last_node = last_node;
        solve(root,temp_last_node,diff);
        return diff;
    }
int main()
{
	return 0;
}