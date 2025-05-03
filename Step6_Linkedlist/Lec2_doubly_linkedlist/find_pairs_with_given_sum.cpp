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
vector<pair<int,int>> func1(Node* head,int k){

    vector<pair<int,int>> ans;
    if(head==NULL){
        return ans;
    }
    Node* left=head;
    Node* right=head;
    while(right!=NULL){
        right=right->next;
    }
    while(left->data < right->data){
        if(right->data+left->data==k){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->back;
        }
        else if(right->data+left->data<k){
            left=left->next;

        }
        else{
            right=right->back;
        }
    }
    return ans;

}
int main(){

    vector<int> arr={6,2,6};

    Node* head=arr2DLL(arr);
    
    

}