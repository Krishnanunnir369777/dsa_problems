#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector < vector < int >>func1(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    return rotated;
}

void func2(vector < vector < int >> & mat) {

    int n = mat.size();

    //transpose
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j],[i]);
        }
    }
    //reversing each row of the matrix
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
    

}
int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //vector < vector < int >> rotated = rotate(arr);

   // cout << "Rotated Image" << endl;
   func2(arr);
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout <<endl;
    }

}