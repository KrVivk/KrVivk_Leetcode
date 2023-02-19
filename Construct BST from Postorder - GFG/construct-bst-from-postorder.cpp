//{ Driver Code Starts
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/


Node* constructTreeUtil(int post[], int* postIndex,
						int key, int min, int max, int size)
{
	if (*postIndex < 0)
		return NULL;

	Node* root = NULL;

	if (key > min && key < max)
	{
		root = new Node(key);
		*postIndex = *postIndex - 1;

		if (*postIndex >= 0)
		{
		root->right = constructTreeUtil(post, postIndex, post[*postIndex],
										key, max, size );

		root->left = constructTreeUtil(post, postIndex, post[*postIndex],
										min, key, size );
		}
	}
	return root;
}

Node *constructTree (int post[], int size)
{
	int postIndex = size-1;
	return constructTreeUtil(post, &postIndex, post[postIndex],
							INT_MIN, INT_MAX, size);
}