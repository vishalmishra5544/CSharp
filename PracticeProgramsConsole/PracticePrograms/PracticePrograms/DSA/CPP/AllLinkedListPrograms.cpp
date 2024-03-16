#include<bits/stdc++.h>
using namespace std;
Node *sortedInsert(Node* head, int data)
    {
       //Your code here
      if(head == NULL) {
        Node* newNode = new Node(data);
        newNode->next = newNode;
        return newNode;
       }
       if(head->data>=data)  // if element is to be inserted first
       {
           Node* dum=new Node(data);
           dum->next=head;
           Node* temp=head;
           while(temp->next!=head)
           {
               temp=temp->next;
           }
           temp->next=dum;
           return dum;
       }
       else if(head->data<data)  // if element is inserted between or at the end 
       {
           Node*temp=head->next;
           Node* prev=head;
           while(temp->data<data and temp!=head)
           {
               prev=temp;
               temp=temp->next;
           }
           if(temp==head)  // if element is inserted at end 
           {
               Node* dum3=new Node(data);
               prev->next=dum3;
               dum3->next=temp;
               return head;
           }
           else {  // for simply inserting the element in between 
               Node* dum2=new Node(data);
           prev->next=dum2;
           dum2->next=temp;
           return head;
               
           }
           
           
       }
       return NULL;
    }
  Node* removeLeadingZeros(Node* head) {
        while(head && head->data == 0)
            head = head->next;
        return head;
    }
    
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while(curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    int length(Node* head) {
        int len = 0;
        while(head) {
            head = head->next;
            len++;
        }
        return len;
    }
    
    // head2 > head1
    bool isGreater(Node* head2, Node* head1) {
        int len2 = length(head2), len1 = length(head1);
        if(len2 > len1) return true;
        if(len2 < len1) return false;
        while(head2 && head1) {
            int val2 = head2->data, val1 = head1->data;
            if(val2 > val1) return true;
            if(val2 < val1) return false;
            head2 = head2->next;
            head1 = head1->next;
        }
        return false;
    }

    Node* subLinkedList(Node* head1, Node* head2) {
        head1 = removeLeadingZeros(head1);
        head2 = removeLeadingZeros(head2);
        
        if(isGreater(head2, head1))
            swap(head1, head2);

        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node* dummy = new Node(-1);
        Node* runner = dummy;
        
        bool carry = false;
        while(head1 || head2) {
            int val1 = 0, val2 = 0;
            
            if(head1) {
                val1 = head1->data;
                head1 = head1->next;
            }
            if(head2) {
                val2 = head2->data;
                head2 = head2->next;
            }
            
            if(carry) {
                val1--;
                carry = false;
            }
            int curr = val1 - val2;
            if(curr < 0) {
                curr += 10;
                carry = true;
            }
            Node* newNode = new Node(curr);
            runner->next = newNode;
            runner = runner->next;
        }
        
        Node* res = dummy->next;
        res = reverse(res);
        res = removeLeadingZeros(res);
        
        if(res == NULL)
            return new Node(0);
        
        return res;
//Detect Loop in linked list
bool detectLoop(Node* head)
    {
       Node *slow = head;
       Node *fast = head;
       while(fast!=NULL && fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
            return true;
       }
       return false;
    }

//reverse a linked list
struct Node* reverseLinkedList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* prev=NULL;
        Node* curr=head;
        Node* nxt;
        while(curr !=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        return prev;
    }
//https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1
void reverselist(Node *&head)
    {
    	Node* prev = NULL, *curr = head, *next;
    	
    	while (curr)
    	{
    		next = curr->next;   // storing value for next node
    		curr->next = prev;   // linking node to previous node
    		prev = curr;         // updating value of prev node
    		curr = next;         // updating value of current node
    	}
    	head = prev;
    }
    
    Node *mergelist(Node *head1, Node *head2)
    {
    	if (!head1) return head2;  // base cases
    	if (!head2) return head1;  // base cases
    	
    	Node *temp = NULL;
    	
    	if (head1->data < head2->data)
    	{
    		temp = head1;     // picking the lower value
    		head1->next = mergelist(head1->next, head2);
    		// recursively merging the remaining list
    	}
    	else
    	{
    		temp = head2;     // picking the lower value
    		head2->next = mergelist(head1, head2->next);
    		// recursively merging the remaining list
    	}
    	return temp;
    }
    
    void splitList(Node *head, Node **Ahead, Node **Dhead)
    {
    	*Ahead = new Node(0);
    	    // first node for the list (will be discarded later)
    	*Dhead = new Node(0);
    	    // first node for the list (will be discarded later)
    	
    	Node *ascn = *Ahead;
    	Node *dscn = *Dhead;
    	Node *curr = head;
    	
    	while (curr)
    	{
    	    // first element goes to ascending list
    		ascn->next = curr;
    		ascn = ascn->next;
    		curr = curr->next;
    		
    		if (curr)
    		{
    		    // second element goes to descending list
    			dscn->next = curr;
    			dscn = dscn->next;
    			curr = curr->next;
    		}
    	}
    	ascn->next = NULL;
    	dscn->next = NULL;
    	*Ahead = (*Ahead)->next;   // discarding first element
    	*Dhead = (*Dhead)->next;   // discarding first element
    }
    
    void sortLinkedListNonDecreasing(Node **head)
    {
    	Node *Ahead, *Dhead;
    	splitList(*head, &Ahead, &Dhead);
    	// function to split the list
    	// Ahead stores the elements with even index (0,2,4...)
    	// Dhead stores elements with odd index
    	
    	reverselist(Dhead);
    	// reversing list with head Dhead since it contains
    	// elements in decreasing order
    	
    	*head = mergelist(Ahead, Dhead);
    	// merging back both lists in increasing order
    }

//https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1
//Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
       // Your code here
       if(del_node!=NULL && del_node->next!=NULL)
       {
           Node *temp=del_node->next;
           del_node->data=del_node->next->data;
           del_node->next=del_node->next->next;
           free(temp);
       }
       
    }
int main()
{
    return 0;
}