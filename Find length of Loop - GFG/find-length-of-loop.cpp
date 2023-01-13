//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(Node* head)
{
    //using two pointers and moving one pointer(slow) by one node and 
    //another pointer(fast) by two nodes in each iteration.
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast!=slow )
    {
        //if the node pointed by first pointer(fast) or the node 
        //next to it is null, then loop is not present so we return 0.
        if( fast==NULL || fast->next==NULL ) 
        return 0;
        
        fast = fast->next->next;
        slow = slow->next;
    }
    //both pointers now point to the same node in the loop.
    
    int size = 1;
    fast = fast->next;
    
    //we start iterating the loop with first pointer and continue till 
    //both pointers point to same node again.
    while( fast!=slow )
    {
        fast = fast->next;
        //incrementing the counter.
        size++;
    }
    //returning the length of the loop.
    return size;
}