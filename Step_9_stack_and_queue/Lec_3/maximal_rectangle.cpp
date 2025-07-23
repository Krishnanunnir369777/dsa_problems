#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func(vector<int>& arr){
    int n=arr.size();
    stack<int> st;
    int maxi=0;
    for(int i=0;i<=n;i++){
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
  
  

int maximal_area(vcetor<vector<char>>& matrix){
    if(matix.empty() || matrix[0].empty()){
        return 0;
    }
    int row=matrix.size();
    int col=matrix[0].size();
    vector<int> heights(col,0);
    int maxArea=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            heights[j]=(matrix[i][j]=='1') ? heights[j]+1 :0;
        }
        maxArea=max(maxArea,func(heights));
    }

    return maxArea;

}

int main(){
    vector<vector<char>> matrix={{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    int ans=maximal_area(matrix);
    cout<<ans; 
}