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
Node* func1(Node* head){

    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextnode=temp->next;

        while(nextnode!=NULL  && nextnode->data==temp->data){
            Node* dummynode=nextnode;
            nextnode=nextnode->next;
            delete dummynode;
        }
        temp->next=nextnode;
        if(nextnode!=NULL){
            nextnode->back=temp;
        }
        temp=temp->next;
    }
    return head;
    
    
    
}
int main(){

    vector<int> arr={1,1,1,2,3,3,4,4,5,5,6,6};

    Node* head=arr2DLL(arr);
    head=func1(head);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    

}