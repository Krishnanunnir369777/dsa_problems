#include <bits/stdc++.h>
using namespace std;

int func1(vector<int>& arr){    //Time Complexity: O(N*N ) 
    int n=arr.size();
    int max_area=0;
    
    for(int i=0;i<n;i++){
        int min_height=INT_MAX;
        for(int j=i;j<n;j++){
            min_height=min(min_height,arr[j]);
            max_area=max(max_area,min_height*(j-i+1));
        }
    }
    return max_area;
}

int func2(vector < int > & heights) {  //Time Complexity: O( N )

    int n = heights.size();
    stack < int > st;
    int leftsmall[n], rightsmall[n];

    for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        st.pop();
      }
      if (st.empty())
        leftsmall[i] = 0;
      else
        leftsmall[i] = st.top() + 1;
      st.push(i);
    }
    // clear the stack to be re-used
    while (!st.empty())
      st.pop();

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();

      if (st.empty())
        rightsmall[i] = n - 1;
      else
        rightsmall[i] = st.top() - 1;

      st.push(i);
    }

    int maxA = 0;
    for (int i = 0; i < n; i++) {
      maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
}

int func3(vector<int>& arr){
  int n=arr.size();
  stack<int> st;
  int maxi=0;
  for(int i=0;i=<n;i++){
    while(!st.empty() && ((i==n) || arr[st.top()]>=arr[i])){
      int height=arr[st.top()];
      st.pop();
      int width;
      if(st.empty()){
        width=i;
      }

      else{
        width=i-st.top()-1;
      }
      maxi=max(maxi,width*height);
    }
    st.push(i);
  }
  return maxi;
}


int main(){

    vector<int> arr={2,1,5,6,2,3};
    cout<<func3(arr);
}