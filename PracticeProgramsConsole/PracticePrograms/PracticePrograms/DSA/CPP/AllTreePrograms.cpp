#include<bits/stdc++.h>
using namespace std;

   void dfsToStorePath(Node *root,int k,vector<Node*> &vec,unordered_set<Node*> &s,int level){
        if(!root)return;
        if(!root->left and !root->right){
            if(k==0){
                s.insert(root);
            }
            else if(level-k>=0){
                s.insert(vec[level-k]);
            }
            return;
        }
        vec.push_back(root);
        dfsToStorePath(root->left,k,vec,s,level+1);
        dfsToStorePath(root->right,k,vec,s,level+1);
        vec.pop_back();
    }
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
        //Add your code here.
        vector<Node*> vec;
        unordered_set<Node*> s;
        dfsToStorePath(root,k,vec,s,0);
        return s.size();
    }

    Node * LCA(Node * root, int a, int b){
        if(root == NULL || root->data == a || root->data == b){
            return root;
        }
        
        Node * left = LCA(root->left,a,b);
        Node * right = LCA(root->right,a,b);
        
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }
    }
    
    int dist(Node * root, int a,int d){
        
        if(root == NULL){
            return 0;
        }
        
        if(root->data == a){
            return d;
        }
        
        int left = dist(root->left,a,d+1);
        int right = dist(root->right,a,d+1);
        
        return max(left,right);
    }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        
        
        Node* lca = LCA(root,a,b);
        
        int dista = dist(lca,a,0);
        int distb = dist(lca,b,0);
        
        return dista+distb;
        
    }
int main()
{
	return 0;
}