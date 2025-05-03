#include <bits/stdc++.h>
using namespace std;
#include <iostream>

int func1(string s){

    int n=s.length();
    if(n==0 || n==1){
        return n;
    }
    int maxans=INT_MIN;
    for(int i=0;i<n;i++){
        unordered_set<int> set;
        for(int j=i;j<n;j++){
            if(set.find(s[j])!=set.end()){
                maxans=max(maxans,j-i);
                break;
            }
            set.insert([s[j]]);
        }
    }
    return maxans;
}

int func2(string str) {   

    if(str.size()==0)
        return 0;
    int maxans = INT_MIN;
    unordered_set < int > set;
    int l = 0;
    for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
    {
      if (set.find(str[r]) != set.end()) //if duplicate element is found
      {
        while (l < r && set.find(str[r]) != set.end()) {
          set.erase(str[l]);
          l++;
        }
      }
      set.insert(str[r]);
      maxans = max(maxans, r - l + 1);
    }
    return maxans;
}


int func3(string s) {
    vector < int > mpp(256, -1);

  int left = 0, right = 0;
  int n = s.size();
  int len = 0;
  while (right < n) {
    if (mpp[s[right]] != -1)
      left =mpp[s[right]] + 1;

    mpp[s[right]] = right;

    len = max(len, right - left + 1);
    right++;
  }
  return len;
    
}
  
int main(){
    string s="abcabcbb";
    cout<<func2(s);
}