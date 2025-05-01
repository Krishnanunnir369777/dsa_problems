#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(vector<vector<int>>& mat){  //O(n^2)
    int n=mat[0].size();
    vector<int> KnowMe(n,0);
    vector<int> Iknow(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                KnowMe[j]++;
                Iknow[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(KnowMe[i]==(n-1) && Iknow[i]==0){
            return i;
        }
    }
    return -1;

}
int func2(vector<vector<int>>& mat){   //O(n)
    int n=mat.size();
    stack<int> st;

    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()>1){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(mat[a][b]){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }
    int c=st.top();
    for(int i=0;i<n;i++){
        if(i==c){
            continue;
        }
        if(mat[c][i] || !mat[i][c]){
            return -1;
        }
    }
    return c;
}

int func3(vector<vector<int>>& mat){
    int n=mat.size();
    int top=0;
    int bottom=n-1;
    while(top<bottom){
        if(mat[top][bottom]){
            top++;
        }
        else{
            bottom--;
        }
    }
    int c=top;
    for(int i=0;i<n;i++){
        if(i==c)continue;
        if(mat[c][i] || !mat[i][c]){
            return -1;
        }
    }
    return c;
}

int main(){
    vector<vector<int>> mat={{ 0, 1, 0 },
                             { 0, 0, 0 },
                             { 0, 1, 0 }};
    cout<<func3(mat);
    
}