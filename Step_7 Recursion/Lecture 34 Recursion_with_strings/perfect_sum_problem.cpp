#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int cnt1=0;
void solve1(vector<int>&nums,vector<int> output,int index,int target){  //Each element in nums can either be included or excluded, leading to 2 choices per element.
                                                                      // If the input array has n elements, the recursion will generate 2𝑛^2 nsubsets.

    //base case                                                   //overall complexity is:O(n*2^n)
    if(index>=nums.size()){
        int sum=0;
        for(int i=0;i<output.size();i++){
            sum+=output[i];
        }
        if(sum==target){
            cnt1++;
        }
        return ;
    }

    //exclude
    solve1(nums,output,index+1,target);

    //include
    int element=nums[index];
    output.push_back(element);
    solve1(nums,output,index+1,target);
}
void func1(vector<int>& nums,int target){

    vector<int> output;
    int index=0;
    solve1(nums,output,index,target);
    
}


//optimised


int cnt2=0;
void solve2(vector<int>& nums, int index, int currentSum, int target) {              //O(2^n)
    // Base case
    if (index == nums.size()) {
        if (currentSum == target) {
            cnt2++;
        }
        return;
    }

    // Exclude the current element
    solve2(nums, index + 1, currentSum, target);

    // Include the current element
    solve2(nums, index + 1, currentSum + nums[index], target);
} 
void func2(vector<int>& arr,int target){
    solve2(arr,0,0,target);
}



int main(){
    vector<int> arr={5, 7, 8};
    int target=3;
    
    func2(arr,target);
    cout<<cnt1;
    

}