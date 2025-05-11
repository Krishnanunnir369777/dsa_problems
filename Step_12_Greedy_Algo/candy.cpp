#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func1(vector<int>& ratings) { //O(3n)

        int n=ratings.size();
        int left[n];
        int right[n];
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            else{
                left[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
            else{
                right[i]=1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=max(left[i],right[i]);
        }
        return sum;
    }

    int func2(vector<int>& ratings) { // space and time optimised than previous
        int n=ratings.size();
        int left[n];
        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
            else
                left[i]=1;
        }
        int curr=1,right=1,sum=max(left[n-1],1);
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                curr=right+1;
            else
                curr=1;
            right=curr; // right is updated outside if else
            sum+=max(left[i],curr);
        }
        return sum;
        
    }
    int func3(vector<int>& ratings) {  // most optimised 
        
        int sum=1,i=1;
        int n=ratings.size();
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peak){
                sum+=down-peak;
            }
        }
        return sum;
        
    }

    int main(){
        vector<int> ratings={1,0,2};
        cout<<func1(ratings);
    }

