#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int func1(string s){
    int n=s.size();
    int ans=0;
    for(auto i=0;i<n;i++){
        int cnt[26]={},max_f=0,min_f=0;
        
        for(auto j=i;j<n;j++){
            int idx=s[j]-'a';
            max_f=max(max_f,++cnt[idx]);

            if(min_f>=cnt[idx]-1){
                
                min_f=cnt[idx];

                for (int k = 0; k < 26; ++k)
                //finding minimum frequency of all characters.
                min_f = min(min_f, cnt[k] == 0 ? INT_MAX : cnt[k]);
            }

            ans+=max_f-min_f;

        }
    }
    return ans;
}