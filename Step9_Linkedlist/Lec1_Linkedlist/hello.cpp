#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node* next;// Pointer to the next node in the linked list
    
    public:
    Node (int data1,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node (int data1){
        data=data1;
       
    }
};
int main(){

    vector<int> arr={1,2,3,4,5};
   
    // Create a Node 'x' with the first element of the vector and a null next reference
    Node x = Node(arr[0], nullptr);

    // Create a pointer 'y' pointing to the Node 'x'
    Node* y = &x;

    //Node* y=new Node(arr[0],nullptr);
    
    cout<<y-> next;


    
}