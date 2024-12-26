#include <iostream>
using namespace std;


class Hero{


    private:
    int health;

    public:
    char level;

    Hero(){
        cout<<"constructor called "<<endl;
    }

    //paramerterised constructor
    Hero(int health){
        cout<<"this "<<this<<endl;
        this->health=health;
    }

    Hero(int health,char level){
        
        this->level=level;   // we copied input level in object level
        this->health=health;
    }
    
    void print(){
        cout<<level<<endl;
    }
    

    int gethealth(){

        return health;
    }
    char getlevel(){
        return level;
    }

    void sethealth(int h){
        health=h;
    }
    void setlevel(char ch){
        level=ch;
    }

    

    
};  


int main(){

    // static allocation
    Hero a(1);
    //cout<<"addres of a "<<&a<<endl;
    a.print();
    

    //dynamically
    Hero *h=new Hero;
    h->print();


    Hero temp(22,'B');
    temp.print();


    
}