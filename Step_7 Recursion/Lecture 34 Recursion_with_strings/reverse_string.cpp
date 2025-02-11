#include <iostream>
using namespace std;


void reverse(string &s,int i,int j){
    //base case
    if(i>j){
        return ;
    }
    swap(s[i],s[j]);
    i++;
    j--;
    reverse(s,i,j);
}
int main(){


    string name="abcde";
    int n=name.length();
    reverse(name,0,n-1);
    for(int i=0;i<n;i++){
        cout<<name[i]<<" "<<endl;
    }

}