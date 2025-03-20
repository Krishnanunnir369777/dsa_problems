#include <bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int start,end,maxSize,curSize;
    public:
      Queue(){
        arr=new int[16];
        start=-1;
        end=-1;
        curSize=0;
      }
    Queue(int maxSize){
        (*this).maxSize=maxSize;
        arr=new int[maxSize];
        start=-1;
        end=-1;
        curSize=0;
    }
    void push(int newElement){
        if(curSize==maxSize){
            cout<<"full"<<endl;
            exit(1);
        }
        if(end=-1){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%maxSize;
        }
        arr[end]=newElement;
        cout<<"the element is "<<newElement<<endl;
        curSize++;
    }
    int pop(){
        if(start=-1){
            cout<<"queue is empty "<<endl;
        }
        int popped=arr[start];
        if(curSize==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%maxSize;
        }
        curSize--;
        return popped;
    }
    int top(){
        if(start==-1){
            cout<<"queue is empty"<<endl;
            exit(1);
        }
        return arr[start];
    }
    int size(){
        return curSize;
    }
};

int main() {
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;
  
    return 0;
  }