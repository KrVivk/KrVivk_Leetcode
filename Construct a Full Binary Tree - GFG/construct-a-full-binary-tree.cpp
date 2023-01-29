//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

Node* constructBinaryTree(int pre[], int preMirror[], int size);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
Node* constructBinaryTree(int pre[], int preMirror[], int size)
{
    // Code here
    if(size == 0)
        return  NULL;
    map<int,int> mp;
    Node *root  =  new Node(pre[0]);
    stack<Node*> st;
    st.push(root);
    for(int i = 0; i < size ; i ++){
        mp[preMirror[i]] = i;
    }
    int i = 1;
    while(i < size){
        int data = pre[i];
        Node *res = new  Node(data);
        while(!st.empty()){
            Node *temp = st.top();
            if(mp[temp->data] < mp[data]){
                if(!temp->left){
                    temp->left = res;
                    st.push(res);
                }
                else{
                    temp->right  =res;
                    st.pop();
                    st.push(res);
                }
                break;
            }
            else{
                st.pop();
            }
        }
        i++;
    }
    return root;
}