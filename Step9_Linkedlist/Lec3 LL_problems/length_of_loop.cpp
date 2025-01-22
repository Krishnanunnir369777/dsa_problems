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
int  func1(Node* head){
    Node* temp=head;
    unordered_map<Node*,int> mpp;
    
    int cnt=0;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){

            return cnt-mpp[temp];
        }
        mpp[temp]=cnt;
        
        temp=temp->next;

        cnt++;
    }
    return 0;

}
// Function to detect a loop in a linked list
// and return the starting node of the loop
Node* detectLoop(Node* head) {
    
    // Use temp to traverse the linked list
    Node* temp = head;
    
    // hashmap to store all visited nodes
    unordered_map<Node*, int> mp;
    
    // Traverse the list using temp
    while(temp!=NULL){
        // check if temp has been encountered again
        if(mp.count(temp)!=0){
            // A loop is detected hence return temp
            return temp;
        }
        // store temp as visited
        mp[temp] = 1;
        // iterate through the list
        temp = temp->next;
    }

    // If no loop is detected, return nullptr
    return nullptr; 
}

int findLength(Node* slow, Node* fast){             //optimised

    
    // count to keep track of 
    // nodes encountered in loop
    int cnt = 1;
    
    // move fast by one step
    fast = fast->next;
    
    // traverse fast till it 
    // reaches back to slow
    while(slow!=fast){
        
        // at each node increase
        // count by 1 and move fast
        // forward by one step
        cnt++;
        fast = fast->next;
    }
    
    // loop terminates when fast reaches
    // slow again and the count is returned
    return cnt;
}
// Function to find the length
// of the loop in a linked list
int func2(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Traverse the list to detect a loop
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;     
        // Move fast two steps
        fast = fast->next->next;

        // Step 2: If the slow and fast pointers
        // meet, there is a loop
        if (slow == fast) {
            // return the number of nodes
            // in the loop
            return findLength(slow, fast);
        }
    }

    // Step 3: If the fast pointer
    // reaches the end, there is no loop
    return 0; 
}

   


int main(){

    vector<int> arr={1,2,3,4,5};
    Node* head=arr2ll(arr);
    
    cout<<func2(head);
    
    
    //cout<<lengthofll(head);

}