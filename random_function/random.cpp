#include <iostream>
using namespace std;
#include <bits/stdc++.h>
string result(string s)
{
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    
    //Iterate the string and keep on adding to form a word
    //If empty space is encountered then add the current word to the result
    while(left==' '){
        left++;
    }
    while(right==' ' && right>=0){
        right--;
    }
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }
    
    //If not empty string then add to the result(Last word is added)
    if (temp!="") {
        if (ans!="") ans = temp + "" + ans;
        else ans = temp;
    }
    
    return ans;    
}
int main()
{
    string st="  TUF is great for interview preparation  ";
    
    string ans=result(st);
    for(int i=0;i<ans.length();i++){
        cout<<ans[i];
    }
    return 0;
}
