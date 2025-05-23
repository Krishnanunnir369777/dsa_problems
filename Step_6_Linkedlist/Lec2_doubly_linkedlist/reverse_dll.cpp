#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};
Node* arr2DLL(vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;

}
Node* func1(Node* head){   //Time Complexity : O(2N)

    // if head is empty or there is only one element
    // we can directly just return the head
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* temp=head;

    stack<int> st;

    while(temp!=0){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=0){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}

// Function to reverse a doubly linked list
// In-place link exchange method
Node* func2(Node* head) {
    
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        // No change is needed;
        // return the current head
        return head; 
    }
    
     // Initialize a pointer to
     // the previous node
    Node* prev = NULL;  
    
    // Initialize a pointer to
    // the current node
    Node* current = head;   

    // Traverse the linked list
    while (current != NULL) {
        // Store a reference to
        // the previous node
        prev = current->back; 
        
        // Swap the previous and
        // next pointers
        current->back = current->next; 
        
        // This step reverses the links
        current->next = prev;          
        
        // Move to the next node
        // in the original list
        current = current->back; 
    }
    
    // The final node in the original list
    // becomes the new head after reversal
    return prev->back;
}

int main(){

    vector<int> arr={6,7,8};

    Node* head=arr2DLL(arr);
    head=func3(head);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    

}