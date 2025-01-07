#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class A {
    public:

    void func(){
        cout<<" i am a"<<endl;
    }
};
class B{
    public:

    void func(){
        cout<<" i am b"<<endl;
    }
};
class C: public A,public B{
    
};
int main(){

    C obj;
   // obj.func(); // error ambiguity

   obj.A::func();
   obj.B::func();


}