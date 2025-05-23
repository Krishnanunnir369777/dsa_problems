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

 Node* func(Node* head,int n) {
        int cnt=0;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        Node* tail=head;
        while(tail!=NULL){
            cnt++;
            tail=tail->next;
        }
        if(n==cnt){
            head=head->next;
            return head;
        }
        int k=(cnt-n)+1;
        Node* temp=head;
        int cnt2=0;
        while(temp!=NULL){
            cnt2++;
            if(cnt2+1==k){
                temp->next=temp->next->next;
                return head;

            }
            temp=temp->next;
        }
        return head;
}

int main(){

    vector<int> arr={1,2};
    Node* head=arr2ll(arr);
    head=func(head,1);
    Node* temp=head;
    
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    //cout<<lengthofll(head);

}