                                
#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for
// the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Global variable to
    // store the diameter
    int diameter = 0;  

    // Function to calculate
    // the height of a subtree
    int calculateHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        // Recursively calculate the
        // height of left and right subtrees
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        // Calculate the diameter at the current
        // node and update the global variable
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height
        // of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to find the
    // diameter of a binary tree
    int func1(Node* root) {             
        // Start the recursive
        // traversal from the root
        calculateHeight(root);

        // Return the maximum diameter
        // found during traversal
        return diameter;
    }






    int func(int& diameter,Node* root){
        if(root==NULL){
            return 0;
        }
        int left=func(diameter,root->left);
        int right=func(diameter,root->right);

        diameter=max(diameter,left+right);

        return 1+max(left,right);
    }
    int func2(Node* root) {
        int diameter=0;
        func(diameter,root);

        return diameter;
        
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

    // Creating an instance of the Solution class
    Solution solution;

    // Calculate the diameter of the binary tree
    int diameter = solution.func2(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
                                
                            