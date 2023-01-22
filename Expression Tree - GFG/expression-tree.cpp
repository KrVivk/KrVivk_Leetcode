//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}



// } Driver Code Ends
/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

class Solution{
  public:
    int toInt(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) num = num * 10 + (int(s[i]) - 48);
        return num;
    }
    void inorder(node* root) {
        if (root) {
    
            cout << root->data << " ";
            inorder(root->left);
            inorder(root->right);
        }
    }
    
    int evalTree(node* root) {
        // empty tree
        if (!root) return 0;
    
        // leaf node i.e, an integer
        if (!root->left && !root->right) return stoi(root->data);
    
        // Evaluate left subtree
        int l_val = evalTree(root->left);
    
        // Evaluate right subtree
        int r_val = evalTree(root->right);
    
        // Check which operator to apply
        if (root->data == "+") return l_val + r_val;
    
        if (root->data == "-") return l_val - r_val;
    
        if (root->data == "*") return l_val * r_val;
    
        return l_val / r_val;
    }

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}

// } Driver Code Ends