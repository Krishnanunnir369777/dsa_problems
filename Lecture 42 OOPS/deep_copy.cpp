#include <iostream>
using namespace std;
#include <cstring>

class Hero{


    private:
    int health;

    public:
    char level;
    char *name;

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

    
};  


int main(){

    Hero hero1;
    hero1.sethealth(12);
    hero1.setlevel('D');
    char name[7]="Babbar";
    hero1.setname(name);

    hero1.print();


    Hero hero2(hero1);
    hero2.print();


    hero1.name[0]='G';
    hero1.print();

    hero2.print();


}