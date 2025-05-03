#include <bits/stdc++.h>
using namespace std;

struct Queue{                          //O(2*N) time complexity
    stack<int> s1,s2;

    void Push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int Pop(){
        if(s1.empty()){
            cout<<"stack is empty"<<endl;
            exit(0);
        }
        int val=s1.top();
        s1.pop();
        return val;
    }
    int Top(){
        if (s1.empty()) {
            cout << "Stack is empty";
            exit(0);
          }
          return s1.top();
    }
    int size(){
        return s1.size();
    }
};
int main() {
    Queue q;
    q.Push(3);
    q.Push(4);
    cout << "The element poped is " << q.Pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.size() << endl;
  }