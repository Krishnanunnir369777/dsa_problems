#include <iostream>
using namespace std;
#include <cstring>

class Hero{


    private:
    int health;

    public:
    char level;
    char *name;
    static int timetocomplete;

    Hero(){
        cout<<"default constructor called  "<<endl;
        name=new char[100];
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

        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        cout<<"copy constructor called"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }
    
   
    
    void print(){
        cout<<endl;
        cout<<" Name: " <<this->name<<endl;
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

    void setname(char name[]){
        strcpy(this->name,name);
    }
    static int random(){

       // cout<<this->health<<endl;    // error will showit can only access static members

       return timetocomplete;


    }
    //Destructor
    ~Hero(){
        cout<<"destructor called "<<endl;
    }

    
};  

int Hero::timetocomplete=5; // we need to initialize like this

int main(){


    cout<<Hero::random()<<endl;
    cout<<Hero::timetocomplete<<endl;

    Hero a;
    cout<<a.timetocomplete<<endl;
    

    Hero b;
    b.timetocomplete=10;
    cout<<a.timetocomplete<<endl;
    cout<<b.timetocomplete<<endl;








    return 0;



}