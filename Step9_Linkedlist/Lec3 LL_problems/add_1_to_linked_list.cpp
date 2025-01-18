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


int addcarry(Node* head){
    if(head==NULL){
        return 1;
    }
    int res=head->data+addcarry(head->next);
    head->data=res%10;

    return res/10;
}
Node* func(Node* head){               // using recursion
      
    int carry=addcarry(head);
    if(carry!=0){
        Node* newhead=new Node(carry);
        newhead->next=head;
        return newhead;
    }
    return head;
}
int main(){

    vector<int> arr={1,2,3,4,5};
    Node* head=arr2ll(arr);
    head=func(head);
    Node* temp=head;
    
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    //cout<<lengthofll(head);

}