


#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

int main() {
    // Create an array
    vector<int> arr = {2, 5, 8, 7};

    // Create first node
    Node* y = new Node(arr[0]);

    // Print memory location of node
    cout << y << '\n';

    // Print data stored in node
    cout << y->data << '\n';

    return 0;
}





