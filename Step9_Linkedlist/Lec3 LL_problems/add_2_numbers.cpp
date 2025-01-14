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
    Node(){
        data=0;
        next=nullptr;
    }
    Node (int data1){
        data=data1;
       
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
Node* func(Node* head1, Node* head2){
    Node* dummy=new Node();
    Node* curr=dummy;
    int carry=0;
    while(head1!=NULL || head2!=NULL){
        int sum=0;
        if(head1!=NULL){
            sum+=head1->data;
            head1=head1->next;
        }
        if(head2!=NULL){
            sum+=head2->data;
            head2=head2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* new_node=new Node(sum%10);
        curr->next=new_node;
        curr=curr->next;
    }
    if(carry){
        Node* node=new Node(carry);
        curr->next=node;
    }
    return dummy->next;
};


int main(){

    vector<int> arr1={2,4,3};
    vector<int> arr2={5,6,4};

    Node* head1=arr2ll(arr1);
    Node* head2=arr2ll(arr2);
    Node* head=func(head1,head2);
    Node* temp=head;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    //cout<<lengthofll(head);

}