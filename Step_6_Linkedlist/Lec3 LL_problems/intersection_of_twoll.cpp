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

int getdifference(Node* head1,Node* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}

//utility function to check presence of intersection
Node* func1(Node* headA,Node* headB) {
    int diff=getdifference(headA,headB);
        if(diff<0){
            while(diff!=0){
                diff++;
                headB=headB->next;
            }
        }
        else{
            while(diff!=0){
                diff--;
                headA=headA->next;
            }
        }
        while(headA!=NULL){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
}
Node* func2(Node* headA,Node* headB){       // optimised
        Node* temp1=headA;
        Node* temp2=headB;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;

            if(temp1==temp2){
                break;
            }
            if(temp1==NULL){
                temp1=headB;
            }
            if(temp2==NULL){
                temp2=headA;
            }
        }
        return temp1;
    
}

int main(){

    vector<int> arrA={1,2,3,4,5};
    vector<int> arrB={6,3,4,5};
    Node* headA=arr2ll(arrA);
    Node*headB=arr2ll(arrB);
    
    Node* temp=func2(headA,headB);
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
   
    
    //cout<<lengthofll(head);

}