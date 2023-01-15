//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends

/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method
Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* curr = head->next;
    head->next = NULL;
    Node* temp = reverse(curr);
    curr->next = head;
    return temp;
}
Node* subLinkedList(Node* l1, Node* l2)
{
    while(l1 && l1->data == 0 ){
        l1 = l1->next;
    }
    while(l2 && l2->data == 0 ){
        l2 = l2->next;
    }
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    int lenght1 = 0 ;
    int lenght2 = 0;
    Node* ptr = l1;
    Node* qtr = l2;
    while(ptr){
        lenght1++;
        ptr = ptr->next;
    }
    while(qtr){
        lenght2++;
        qtr = qtr->next;
    }
    ptr = l1;
    qtr = l2;
    bool same = false;
    if(lenght1 == lenght2){
        while(ptr && qtr){
            if(ptr->data != qtr->data){
                break;
            }
            ptr = ptr->next;
            qtr = qtr->next;
        }
        if(!ptr && !qtr){
            Node* node = new Node(0);
            node->next = NULL;
            return node;
        }
        else{
            if(ptr->data > qtr->data){
                same = true;
            }
        }
    }
    l1 = reverse(l1);
    l2 = reverse(l2);
    if(lenght1 > lenght2){
        ptr = l1;
        qtr = l2;
    }
    else if(lenght1 < lenght2){
        ptr = l2;
        qtr = l1;
    }
    else{
        if(same){
            ptr = l1;
            qtr = l2;
        }
        else{
            ptr = l2;
            qtr = l1;
        }
    }
    int carry = 0;
    while(ptr && qtr){
        ptr->data = ptr->data - carry;
        if(ptr->data > qtr->data){
            ptr->data = ptr->data - qtr->data;
            carry = 0 ;
        }
        else{
            if(ptr->data == qtr->data){
                ptr->data = ptr->data - qtr->data;
                carry = 0 ;
            }
            else{
                ptr->data = (ptr->data + 10) - qtr->data;
                carry = 1;
            }
        }
        ptr = ptr->next;
        qtr = qtr->next;
    }
    while(ptr){
        if(carry){
            if(ptr->data < carry){
                ptr->data = 10 - carry;
                carry = 1;
            }
            else{
                ptr->data = ptr->data - carry;
                carry = 0 ;
            }
        }
        ptr = ptr->next;
    }
    Node* ans = NULL;
    if(lenght1 > lenght2){
        ans = reverse(l1);
    }
    else if(lenght2 > lenght1){
        ans = reverse(l2);
    }
    else{
        if(same){
            ans = reverse(l1);
        }
        else{
            ans = reverse(l2);
        }
    }
    while(ans->next && ans->data == 0){
        ans = ans->next;
    }
    return ans;
}