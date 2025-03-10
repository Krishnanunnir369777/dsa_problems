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
Node* removekth(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;

}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=arr2ll(arr);
    head=removekth(head,5);
    Node* temp=head;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}