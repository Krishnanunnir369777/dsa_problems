
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

    
    Hero h1;
    
    cout<<"health is "<<h1.gethealth()<<endl;
    //cout<<"size : "<<sizeof(h1)<<endl;

    h1.sethealth(7);
    h1.level='a';

    cout<<"health is "<<h1.gethealth()<<endl;
    cout<<"level is "<<h1.level<<endl;
    
}