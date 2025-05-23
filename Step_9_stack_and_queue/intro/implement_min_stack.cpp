#include<bits/stdc++.h>
using namespace std;

class MinStack_1{                    //Space Complexity: O(2N)
    stack<pair<int,int>> st;

    public:
      void push(int x){
        int mini;
        if(st.empty()){
            mini=x;
        }
        else{
            mini=min(x,st.top().second);
        }
        st.push({x,mini});
      }
      void pop(){
        st.pop();
      }
      int top(){
        return st.top().first;
      }
      int getMin(){
        return st.top().second;
      }
};
class MinStack_2{
  stack<long long> st;
  long long mini;
  public:
  MinStack_2(){
    while(!st.empty()){
      st.pop();
    }
    mini=INT_MAX;
  }
  void Push(int value){
    long long val=value;
    if(st.empty()){
      mini=val;
      st.push(val);
    }
    else if(val<mini){
      st.push(2*val-mini);
      mini=val;
    }
    else{
      st.push(val);
    }
  }
  void Pop(){
    if(st.empty()){
      return ;
    }
    long long ele=st.top();
    st.pop();
    if(ele<mini){
      mini=2*mini-ele;
    }

  }
  int Top(){
    long long ele=st.top();
    if(st.empty()){
      return -1;
    }
    else if(ele<mini){
      return mini;
    }
    return ele;
  }
  int getMin(){
    return mini;
  }

};

int main(){
    MinStack_2 m;
    m.Push(1);
    m.Push(2);
    m.Push(7);
    cout<<m.getMin();



}