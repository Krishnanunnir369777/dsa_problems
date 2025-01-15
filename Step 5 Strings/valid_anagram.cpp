#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool func1(string str1, string str2)
{
  // Case 1: when both of the strings have different lengths
  if (str1.length() != str2.length())
    return false;
 
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
 
  // Case 2: check if every character of str1 and str2 matches with each other
  for (int i = 0; i < str1.length(); i++)
  {
    if (str1[i] != str2[i])
      return false;
  }
  return true;
}
bool func2(string s,string t){       // more optimised
    if(s.length()!=t.length()){
        return false;
    }
    unordered_map<char,int> counts;
    for(int i=0;i<s.length();i++){
        counts[s[i]]++;
        counts[t[i]]--;
    }
    for(auto i:counts){
        if(i.second!=0){
            return false;
        }
    }
    return true;
}
int main(){
    string s="anagram";
    string t="nagaram";
    cout<<func2(s,t);
}