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
//https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_set<int> h;
        int pair=0;
        Node *t=head1;
        while(t)
        {
            h.insert(t->data);
            t=t->next;
        }
        t=head2;
        while(t)
        {
            if(h.find(x-t->data)!=h.end())
            {
                pair++;
            }
            t=t->next;
        }
        return pair;
    }
//https://www.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1?page=1&difficulty=Basic&status=unsolved&sortBy=submissions
int sumOfLastN_Nodes(struct Node* head, int n)
{
      if(head==NULL)
       return 0;
      Node* s=head;
      Node* f=head;
      int ans=0;
      while(n-->1)
      {
          f=f->next;
      }
      while(f->next!=NULL)
      {
          s=s->next;
          f=f->next;
      }
      while(s!=f)
      {
          ans+=s->data;
          s=s->next;
      }
      ans+=f->data;
      return ans;
}
//https://leetcode.com/problems/add-two-numbers/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode();
        ListNode* temp=l3;
        ll carry=0;
        while(l1 || l2 || carry){
            if(l1 && l2){
                temp->val=(l1->val+l2->val+carry)%10;
                carry=(l1->val+l2->val+carry)/10;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1){
                temp->val=(l1->val+carry)%10;
                carry=(l1->val+carry)/10;
                l1=l1->next;
            }
            else if(l2){
                temp->val=(l2->val+carry)%10;
                carry=(l2->val+carry)/10;
                l2=l2->next;
            }
            else{
                temp->val=carry;
                carry=0;
            }
            
            if(l1 || l2 || carry){
                temp->next=new ListNode();
                temp=temp->next;
            }
        }
        return l3;
    }
//https://www.geeksforgeeks.org/problems/find-nk-th-node-in-linked-list/1?page=1&difficulty=Basic&status=unsolved&sortBy=submissions
int fractional_node(struct Node *head, int k)
{
    // your code here
    Node *slow=NULL,*fast=head;
    int i=0;
    while(fast!=NULL)
    {
       if(i%k==0)
       {
           if(slow==NULL)
             slow=head;
           else
             slow=slow->next;
           // cout<<slow->data<<" "<<i<<" ";
       }
       fast=fast->next;
       i++;
    }
    return slow->data;
    
}

//https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1
// Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        return mergeSortDoublyLL(head);
    }
    
    Node * mergeSortDoublyLL(Node * head)
    {
        if(head==NULL||head->next==NULL)
          return head;
        //mid
        Node* mid=getMid(head);
        Node* head2=mid->next;
        head2->prev=NULL;
        mid->next=NULL;
        head=mergeSortDoublyLL(head);
        head2=mergeSortDoublyLL(head2);
        return merge(head,head2);
    }
    Node* getMid(Node* head)
    {
        if(head==NULL || head->next==NULL)
         return head;
        Node* fast=head->next,*slow=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* head1,Node *head2)
    {
        if(head1==NULL)
          return head2;
        if(head2==NULL)
          return head1;
        Node *h=new Node(-1),*head=h;
        while(head1&&head2)
        {
            if(head1->data<head2->data)
            {
                head->next=head1;
                head1->prev=head;
                head=head->next;
                head1=head1->next;
            }
            else
            {
                head->next=head2;
                head2->prev=head;
                head=head->next;
                head2=head2->next;
            }
        }
        if(head1)
        {
           head->next=head1;
           head1->prev=head;
        }
        if(head2)
        {
            head->next=head2;
            head2->prev=head;
        }
        head=h->next;
        head->prev=NULL;
        h->next=NULL;
        delete h;
        return head;
    }
 //https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1
  Node* deleteMid(Node* head)
    {
        if(head==NULL)
          return head;
        if(head->next==NULL)
        {
            delete head;
            return NULL;
        }
        Node* slow=head,*fast=head->next;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast&&fast->next==NULL)//even
        {
            fast=slow->next;
            slow->next=slow->next->next;
            delete fast;
        }  
        else//odd
        {
            fast=slow->next;
            slow->data=slow->next->data;
            slow->next=slow->next->next;
            delete fast;
        }
        return head;
    }
//https://www.geeksforgeeks.org/problems/remove-every-kth-node/1
Node* deleteK(Node *head,int K){
      Node *h=head;
      if(K==1)
      {
          while(h)
          {
              Node *t=h;
              h=h->next;
              delete t;
          }
          return head=NULL;
      }
      int count=1;
      while(h)
      {
          while(h&&count<K-1)
          {
            h=h->next;
            count++; 
          }
          if(h&&h->next&&count==K-1)
          {
            Node *t=h->next;
            h->next=t->next;
            delete t;
            h=h->next;
            count=1;
          }
          else return head;
      }
      return head;
    }
//https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        if(num1==NULL||num2==NULL)
         return NULL;
        Node* n1=reverse(trimZero(num1));
        
        Node* n2=reverse(trimZero(num2));
        if(n1==NULL&&n2==NULL)
         return new Node(0);
        Node* head=new Node(-1);
        Node* ans=head;
        int carry=0,sum=0;
        while(n1&&n2)
        {
            sum=(n1->data+n2->data+carry)%10;
            carry=(n1->data+n2->data+carry)/10;
            head->next=new Node(sum);
            head=head->next;
            n1=n1->next;
            n2=n2->next;
        }
        while(n1)
        {
            sum=(n1->data+carry)%10;
            carry=(n1->data+carry)/10;
            head->next=new Node(sum);
            head=head->next;
            n1=n1->next;
        }
        while(n2)
        {
            sum=(n2->data+carry)%10;
            carry=(n2->data+carry)/10;
            head->next=new Node(sum);
            head=head->next;
            n2=n2->next;
        }
        while(carry)
        {
            sum=carry%10;
            carry=carry/10;
            head->next=new Node(sum);
            head=head->next;
        }
        Node *t=ans;
        ans=ans->next;
        delete t;
        return reverse(ans);
    }
    Node * trimZero(Node* head)
    {
        while(head&&head->data==0)
        {
            Node* t=head;
            head=head->next;
            delete t;
        }
        return head;
    }
    Node* reverse(Node* head)
    {
        Node* curr=head,*prev=NULL,*next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void print(Node * head)
    {
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
    }
//https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1
struct Node* arrangeCV(Node* head) {
        // Code here
        unordered_set<char> vowelSet={'a','e','i','o','u'};
        Node* vowel=NULL,*consonant=NULL,*h=head;
        Node* v=NULL,*c=NULL;
        while(h)
        {
            if(vowelSet.find(h->data)!=vowelSet.end())
            {
               if(vowel==NULL)
               {
                   vowel=h;
                   v=vowel;
               }
               else
               {
                 vowel->next=h;
                 vowel=vowel->next;
               }
            }
            else
            {
                if(consonant==NULL)
                {
                    consonant=h;
                    c=consonant;
                }
                else
                {
                    consonant->next=h;
                    consonant=consonant->next;
                }
            }
            h=h->next;
        }
        if(consonant)
            consonant->next=NULL;
        if(vowel)
        {
            vowel->next=c;
            return v;
        }
        else
        {
            return c;
        }
    }
    void print(Node* h)
    {
        while(h)
        {
            cout<<h->data<<" ";
            h=h->next;
        }
    }
//https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1?page=4&difficulty=Basic&sortBy=submissions
void deleteAlt(struct Node *head){
        if(!head)
          return;
        Node*h=head,*t=NULL;
        while(h&&h->next!=NULL)
        {
            t=h->next;
            h->next=t->next;
            delete t;
            h=h->next;
        }
        
    }
int main()
{
    return 0;
}