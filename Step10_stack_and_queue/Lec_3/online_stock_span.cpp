#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int func1(int price) {
    int cnt=1;
    arr.push_back(price);
    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i]<=price){
            cnt++;
        }
        else{
            break;
        }
    }
    return cnt; 
}

int func2(int price) {

    int span=1;

    while(!st.empty() && price>=st.top().first){
        span+=st.top().second;
        st.pop();
    }

    st.push({price,span});
    return span; 
}

int main(){

}