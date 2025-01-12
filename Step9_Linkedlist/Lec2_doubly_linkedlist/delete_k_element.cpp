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
Node* deletehead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}
Node* deletetail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    Node* newtail=temp->back;
    newtail->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
    
}
Node* delete_el(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    Node* knode=head;
    while(knode!=0){
        cnt++;
        if(k==cnt){
            break;
        }
        knode=knode->next;
    }
    Node* prev=knode->back;
    Node* front=knode->next;
    if(prev==NULL && front==NULL){
        return NULL;
    }
    else if(prev==NULL){
        return deletehead(head);
    }
    else if(front==NULL){
        return deletetail(head);
    }
    prev->next=front;
    front->back=prev;
    knode->next=NULL;
    knode->back=NULL;
    delete knode;
    return head;
}
int main(){

    vector<int> arr={6,7,8,9};

    Node* head=arr2DLL(arr);
    head=delete_el(head,2);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    

}