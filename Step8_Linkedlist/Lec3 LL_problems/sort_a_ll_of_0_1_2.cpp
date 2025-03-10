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

 Node* func(Node* head) {
        if (!head || !(head->next))
            return head;

        // creating three dummy nodes to point to beginning of three linked lists.
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);

        // initializing current pointers for three lists.
        Node *zero = zeroD, *one = oneD, *two = twoD;

        // traversing over the list with a pointer.
        Node* curr = head;
        while (curr) {

            // we check data at current node and store the node in it's respective
            // list and update the link part of that list.
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
                curr = curr->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
                curr = curr->next;
            } else {
                two->next = curr;
                two = two->next;
                curr = curr->next;
            }
        }

        // attaching the three lists containing 0s,1s and 2s respectively.
        zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
        one->next = twoD->next;
        two->next = NULL;

        // updating the head of the list.
        head = zeroD->next;

        // deleting dummy nodes.
        delete zeroD;
        delete oneD;
        delete twoD;

        return head;
}

int main(){

    vector<int> arr={2,1,0,0,1,2,2,1};
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