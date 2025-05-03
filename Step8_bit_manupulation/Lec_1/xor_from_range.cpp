#include <bits/stdc++.h>
using namespace std;


int func1(int l, int r) {   //O(n)
    // complete the function here
    int ans=0;
    for(int i=l;i<=r;i++){
        ans=ans^i;
    }
    
    return ans;
}
int func(int n){ 

    int mod=n%4;

    if(mod==0){
        return n;
    }
    else if(mod==1){
        return 1;
    }
    else if(mod==2){
        return n+1;
    }
    else if(mod==3){
        return 0;
    }

    return -1;
}
int func2(int l,int r){           //O(1)

    return func(l-1)^func(r);

}
int main(){

    cout<<func2(4,8);

}