#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class animal{

    public:
    int age;
    int weight;

    public:
    void bark(){
        cout<<"barking"<<endl;

    }
};

class Human{
    public:
    string color;

    public:
    void speak(){
        cout<<"speaking"<<endl;
    }
};
//multiple inheritance

class hybrid: public animal,public Human{


};

int main(){

    hybrid obj1;
    obj1.speak();
    obj1.bark();

}