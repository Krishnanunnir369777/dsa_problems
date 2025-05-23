                                
#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Inorder traversal to populate
    // the vector with BST elements
    void inorder(TreeNode* node, vector<int>& arr){
        if(!node){
            return;
        }
        // Recursive call to the left subtree
        inorder(node->left, arr);
        
        // Push the value of current
        // node into the vector
        arr.push_back(node->val);
        
        // Recursive call to the right subtree
        inorder(node->right, arr);
        return;
    }
public:
    // Function to find the Kth
    // smallest and largest elements in BST
    pair<int, int> func1(TreeNode* node, int k){
        // Vector to store the
        // elements of the BST
        vector<int> arr;
        
        // Perform inorder traversal
        // to populate the vector
        inorder(node, arr);
        
        // Calculate Kth largest
        // and smallest elements
        int kLargest = arr[arr.size() - k];
        int kSmallest = arr[k-1]; 
        
        // Returning a pair containing
        // Kth smallest and largest elements
        return make_pair(kSmallest, kLargest);
    }
    
};




// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main() {
    // Creating a BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;
    
  
    
    Solution solution;

    // Find the Kth smallest and largest elements
    int k = 3; 
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = solution.func1(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    return 0;
}
             




//optimal


class Solution {
public:
    void func(TreeNode* root,int k,int& count,int& ans){
        if(!root || count>=k){
            return ;
        }
        func(root->left,k,count,ans);
        count++;
        if(count==k){
            ans=root->val;
            return ;
        }
        func(root->right,k,count,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int count=0;
        func(root,k,count,ans);

        return ans;
    }
};
                            