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
Node* insert_before_head(Node* head,int val){
    Node* new_head= new Node(val,head,nullptr);
    head->back=new_head;

    return new_head;

}
Node* func(Node* head,int val){
    if(head->next==NULL){
        return insert_before_head(head,val);
    }
    Node* tail=head;

    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* pre=tail->back;
    Node* new_node=new Node(val,tail,pre);
    pre->next=new_node;
    tail->back=new_node;
    
    return head;

}
int main(){

    vector<int> arr={6,7,8,9};

    Node* head=arr2DLL(arr);
    head=func(head,2);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    

}