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
int main()
{
	return 0;
}