#include <iostream>
using namespace std;


int search1(int nums[5],int n, int target) { 
        int s=0; 
        int e=n-1;
        while(s<=e){
          int mid = (s+e)/2;
          if(nums[mid]==target) return mid;
          if(nums[mid]>=nums[0]){
                
                
                //left side
            if(target>=nums[s]  && target<nums[mid]){
              e = mid-1;
            }
            else {
              s = mid+1;
            }
          }
          else{
              //right side
              if(target>nums[mid]  && target<=nums[e]){
                  s = mid+1;
              }
              else{
                  e = mid-1;
              }
          }
        }
          return -1;
    }      
int main(){
    int arr[5]={12, 15, 18, 2, 4};
    int n=5;
    int ans=search1(arr,n,2);
    cout<<ans;

}