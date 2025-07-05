#include <iostream>
using namespace std;

class Solution {
public:
    
    int climbStairs(int n) {  //  (O(2^n))
        if(n==0 || n==1){
            return 1;
        }
        return  climbStairs(n-1)+ climbStairs(n-2);;
    }
};

//Approach 2: Memoization

class Solution {
public:
    int f(int n,unordered_map<int,int>& memo){
        if(n==0 || n==1){
            return 1;
        }
        if(memo.find(n)==memo.end()){
            memo[n]=f(n-1,memo)+f(n-2,memo);
        }
        return memo[n];
    }
    
    int climbStairs(int n) {
        unordered_map<int,int> memo;
        return f(n,memo);
    }
};

// Tabulation

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        vector<int> tabu(n+1);
        tabu[1]=tabu[0]=1;
        for(int i=2;i<=n;i++){
            tabu[i]=tabu[i-1]+tabu[i-2];
        }
        return tabu[n];
    }
};


class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        int prev2=1;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};