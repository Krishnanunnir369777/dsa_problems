#include <iostream>
using namespace std;
#include<bits/stdc++.h>
void rotate_array1(vector<int> &arr,int d){//[Naive Approach] Rotate one by one – O(n * d) Time and O(1) Space
    int n=arr.size();
    for(int i=0;i<d;i++){
        int first_element=arr[0];
        for(int j=0;j<n-1;j++){
            arr[j]=arr[j+1];
        }
        arr[n-1]=first_element;
    }
}
void rotate_array2(vector <int> &arr , int d){ // Using Temporary Array – O(n) Time and O(n) Space
    int n=arr.size();
    // Handle case when d > n
    d%=n;
    // Storing rotated version of array
    vector <int> temp(n);
    // Copy last n - d elements to the front of temp
    for(int i=0;(i+d)<n;i++){
        temp[i]=arr[d+i];
    }
    for(int i=0;i<d;i++){
        temp[n-d+i]=arr[i];
    }
     // Copy the first d elements to the back of temp
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }

}
void rotate_array3(vector<int> &arr,int d){//[Expected Approach 2] Using Reversal Algorithm – O(n) Time and O(1) Space
    int n=arr.size();
    int n = arr.size();
  
    // Handle the case where d > size of array
    d %= n;
  
    // Reverse the first d elements
    reverse(arr.begin(), arr.begin() + d);

    // Reverse the remaining n-d elements
    reverse(arr.begin() + d, arr.end());
  
    // Reverse the entire array
    reverse(arr.begin(), arr.end());
}
    


int main(){
    vector <int> arr={1,2,3,4,5};
    int d=2;
    //int n=arr.size();
    rotate_array2(arr,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }




}