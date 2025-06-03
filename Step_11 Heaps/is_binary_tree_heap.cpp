// C++ Program to Check if a given
// Binary Tree is a Heap

#include <bits/stdc++.h>//O(n)
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

// This function counts the
// number of nodes in a binary tree 
int countNodes(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// This function checks if the
// binary tree is complete or not 
bool isCompleteUtil(Node* root, int index, int numberOfNodes) {
    if (root == nullptr)
        return true;

    // If index assigned to current node is more than 
  	// number of nodes in the tree,
    // then the tree is not complete
    if (index >= numberOfNodes)
        return false;

    // Recur for left and right subtrees
    return isCompleteUtil(root->left, 2 * index + 1, numberOfNodes) &&
           isCompleteUtil(root->right, 2 * index + 2, numberOfNodes);
}

// This function checks the heap property in the tree.
bool isHeapUtil(Node* root) {
    if (root->left == nullptr && root->right == nullptr)
        return true;

    // Node will be in the second-last level
    if (root->right == nullptr) {
        
        // Check heap property at the node
        // No recursive call because no need to
      	// check the last level
        return root->key >= root->left->key;
    } 
    else {

        // Check heap property at the node and recursively 
      	// check the heap property
        // at left and right subtrees
        if (root->key >= root->left->key && root->key >= root->right->key)
            return isHeapUtil(root->left) && isHeapUtil(root->right);
        else
            return false;
    }
}

// Function to check if the binary tree is
// a Heap or not.
bool isHeap(Node* root) {
    
    int nodeCount = countNodes(root);
    int index = 0;

    if (isCompleteUtil(root, index, nodeCount) && isHeapUtil(root))
        return true;
    return false;
}

int main() {

    // Construct the Binary Tree
    //        10
    //       /  \
    //      9    8
    //     / \   / \
    //    7   6 5   4

    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
  
  	if (isHeap(root)) {
      cout << "true";
    } else cout << "false";

    return 0;
}