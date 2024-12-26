#include <iostream>
using namespace std;


class Hero{


    private:
    int health;

    public:
    char level;

    Hero(){
        cout<<"default constructor called  "<<endl;
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

    // copy constructor
    Hero(Hero& temp){
        cout<<"copy constructor called"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }
   
    
    void print(){
        cout<<"health "<<this->health<<endl;
    
        cout<<"level "<<this->level<<endl;
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

    Hero s(7,'K');
    s.print();

//copy constructor
    Hero R(s);
    R.print();


}