                            
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    void func(int curr,int& maxi,Node* root){
        if(root==NULL){
            maxi=max(curr,maxi);
            return ;
        }
        func(curr+1,maxi,root->left);
        func(curr+1,maxi,root->right);
    }
    int maxDepth(Node* root) {
        int maxi=0;
        int curr=0;
        func(curr,maxi,root);

        return maxi;
    }
};




// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    

    Solution solution;
    int depth = solution.maxDepth(root);

    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}
                            
                        