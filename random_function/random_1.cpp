#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* insertHeaad(Node* head,int val){
    Node* temp=new Node(val);
    temp->next=head;
    return temp;
}
Node* reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    stack<int> st;
    Node* temp=head;
    while(temp!=nullptr){
        st.push(temp);
        temp=temp->next;
    }
    
}
int main(){
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    // Creating a linked list with initial elements from the array
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Inserting a new node at the head of the linked list
    head = insertHead(head, val);
    // Printing the linked list
    printLL(head);

    return 0;
    
}

int find_height(Node* root){
    if()
}

bool balanced(Node* root){
    if(root==nullptr){
        return true;
    }
    int left=find_height(root->left);
    int right=find_height(root->right);

    if(abs(left-right)>=1 && ba)
}