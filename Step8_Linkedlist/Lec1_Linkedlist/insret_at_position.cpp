#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node {
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
       
    }
};
Node* arr2ll(vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* insert_at(Node* head,int el,int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(el,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp->next!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x=new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=arr2ll(arr);
    head=insert_at(head,100,4);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}