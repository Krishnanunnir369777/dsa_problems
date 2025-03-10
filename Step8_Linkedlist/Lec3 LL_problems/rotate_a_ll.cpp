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

Node* rotateRight(Node* head, int k) {
        int n=1;
        Node* temp=head;
        if(head==NULL){
            return NULL;
        }
        while(temp->next!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0 ||head->next==NULL){
            return head;
        }
        Node* curr=head;
        int balance=n-k;
        
        while(curr!=NULL){
            balance--;

            if(balance==0){
                temp->next=head;
                Node* ans=curr->next;

                curr->next=NULL;

                return ans;
                
            }
            curr=curr->next;

        }
        return head;
        
        
    }



int main(){

    vector<int> arr={1,2,3,4,5};
    Node* head=arr2ll(arr);
    head=rotateRight(head,2);
    Node* temp=head;
    
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    //cout<<lengthofll(head);

}