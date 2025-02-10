#include <iostream>
using namespace std;
#include <bits/stdc++.h>


class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node (int data1,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    
    Node (int data1){
        data=data1;
        next=nullptr;
    }
};

Node* arr2ll(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover =head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

};

// Function to sort a linked list
// using Brute Force approach
Node* func1(Node* head){                          //Time Complexity: O(N) + O(N log N) + O(N)
    // Create a vector to
    // store node values
    vector<int> arr;
    
    // Temporary pointer to
    // traverse the linked list
    Node* temp = head;
    
    // Traverse the linked list and
    // store node values in the vector
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    
    // Sort the array
    // containing node values
    sort(arr.begin(), arr.end());
    
    // Reassign sorted values to
    // the linked list nodes
    temp = head;
    for(int i = 0; i < arr.size(); i++){
        // Update the node's data
        // with the sorted values
        temp->data = arr[i]; 
        // Move to the next node
        temp = temp->next; 
    }
    
    // Return the head of the
    // sorted linked list
    return head; 
}
Node* mergesorted_ll(Node* list1,Node* list2){
    Node* dummy=new Node(-1);
    Node* temp=dummy;

    while(list1!=NULL && list2!=NULL){
        if(list1->data<list2->data){
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;

        }
    }
    if(list1!=NULL){
        temp->next=list1;
    }
    else{
        temp->next=list2;
    }
    return dummy->next;
}
Node* findmiddle(Node* head){
    if(head==NULL && head->next==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;
}
Node* func2(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* middle=findmiddle(head);

    Node* right=middle->next;
    middle->next=NULL;
    Node* left=head;

    left=func2(left);

    right=func2(right);

    return mergesorted_ll(left,right);


}

int main(){

    vector<int> arr={5,4,3,2,1};
    Node* head=arr2ll(arr);
    head=func2(head);
    Node* temp=head;
    
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    //cout<<lengthofll(head);

}