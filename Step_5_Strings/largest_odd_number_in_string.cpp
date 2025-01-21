#include <iostream>
using namespace std;
#include <string>

string func(string num){

    for(int i=num.size()-1;i>=0;i--){
        if((num[i]-'0')%2!=0){
            return num.substr(0,i+1);
        }
    }
    return "";
}

int main(){
    string num="124574";
    string ans=func(num);

    cout<<ans;
}