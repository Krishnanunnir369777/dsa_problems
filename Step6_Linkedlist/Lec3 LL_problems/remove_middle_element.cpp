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
Node* func1(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    int mid=cnt/2+1;
    temp=head;
    int ans=1;
    while(temp!=NULL){
        if(ans==mid-1){
            temp->next=temp->next->next;
            return head;
        }
        temp=temp->next;
        ans++;
    }
    return head;
}
Node* func2(Node* head){  //optimised
    
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL){

        slow=slow->next;
        fast=fast->next->next;

    }
    slow->next=slow->next->next;
    return head;

}
int main(){

    vector<int> arr={1,2,3,4,5};
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