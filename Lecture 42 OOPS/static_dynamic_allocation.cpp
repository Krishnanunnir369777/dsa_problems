#include <iostream>
using namespace std;


class Hero{


    private:
    int health;

    public:
    char level;

    
    // getter 
    int gethealth(){

        return health;
    }

    char getlevel(){
        return level;
    }

    //setter
    void sethealth(int h){
        health=h;
    }
    void setlevel(char ch){
        level=ch;
    }

    
};  


int main(){

    // static allocation
    Hero a;

    //dynamic
    Hero *b=new Hero;

    




    a.sethealth(1);
    a.setlevel('A');
    cout<<"level is "<<a.level<<endl;
    cout<<"health is "<<a.gethealth()<<endl;

    //dynamically
    Hero *b=new Hero;
    b->sethealth(2);
    b->setlevel('B');
    cout<<"level is "<<(*b).level<<endl;
    cout<<"health is "<<(*b).gethealth()<<endl;

// alternate
    cout<<"level is "<<b->level<<endl;
    cout<<"health is "<<b->gethealth()<<endl;

}