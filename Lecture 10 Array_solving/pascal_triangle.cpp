#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int ncr(int n,int r){
    long long res=1;

    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }

    return (int)(res);
}
vector<vector<int>> pascal1(int n){
    
    vector<vector<int>> ans;
    for(int r=0;r<n;r++){

        vector<int> temp;
        for(int c=0;c<=r;c++){
            temp.push_back(ncr(r,c));
        }
        ans.push_back(temp);
       
    }
    return ans;
}

//optimal O(n2)

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}
int main(){
    int n=5;
    vector<vector<int>> ans=pascal1(n);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}