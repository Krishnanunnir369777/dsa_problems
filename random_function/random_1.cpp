#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(string op, int open, int close, vector<string> &ans){
    if(open == 0 && close == 0){
        ans.push_back(op);
        return;
    }
    //when count of open and close brackets are same then 
    //we have only one choice to put open bracket 
    if(open == close){
        string op1 = op;
        op1.push_back('(');
        solve(op1, open-1, close, ans);
    }
    else if(open == 0){
        //only choice is to put close brackets 
        string op1 = op;
        op1.push_back(')');
        solve(op1, open, close-1, ans);
    }
    
    else{
        string op1 = op;
        string op2 = op;
        op1.push_back('(');
        op2.push_back(')');
        solve(op1, open-1, close, ans);
        solve(op2, open, close-1, ans);
    }
}
vector<string> func1(int n) {
    int open = n;
    int close = n;
    vector<string> ans;
    string op = "";
    solve(op, open, close, ans);
    return ans;
}
int main(){
    vector<string> ans=func1(3);

    for(auto i:ans){
        cout<<i<<endl;
    }

}