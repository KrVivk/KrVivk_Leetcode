//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int fractional_node(struct Node* head,int k);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* ptr,*start = NULL,*ptr1;
        int n,i;
        cin>>n;
        
        for(i=0;i<n;i++)
        {
            int value;
            cin>>value;
            
            ptr=new Node(value);
            
            if(start==NULL)
            {
                start=ptr;
                ptr1=ptr;
            }
            else
            {
                ptr1->next=ptr;
                ptr1=ptr1->next;
            }
        }
        ptr1->next=NULL;
        int k;
        cin>>k;
        int p = fractional_node(start,k);
        cout<<p<<endl;
    }
}

// } Driver Code Ends


/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
int fractional_node(Node* head, int k)
{
    int c = 0, d;
    Node *ptr, *ptr1 = head;
    
    while(ptr1 != NULL)
    {
        c++;
        ptr1=ptr1->next;
    }
    if(c%k==0)
        d=c/k;
    else
        d=(c/k)+1;
    int p=1;
    ptr1=head;
    
    while(p<=c)
    {
        if(p==d)
        {
            return ptr1->data;
        }
        p++;
        ptr1=ptr1->next;
    }
}