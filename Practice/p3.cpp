#include<bits/stdc++.h>
using namespace std;

// Static Polymorphism
int add(int a,int b){
    return a+b;
}

double add(double a,double b){
    return a+b;
}

// Dynamic Polymorphism
class Animal{
public:
   virtual void sound(){
    cout<<"Animal makes Sound";
   }
};

class Dog: public Animal{
public:
   void sound() override{
        cout<<"Dog Barks";
   }
};


//Encapsulation
class Bank{
private:
int amount;
public: 
    Bank(int amount){
        this->amount=amount;
    }
    void credit(int balance){
        amount+=balance;
        cout<<"Credited amount"<<balance<<"Total available Balance is: "<<amount<<endl;
    }
    void debit(int balance){
        if(amount<balance) cout<<"Insufficient Balance"<<endl;
        else{
            amount-=balance;
            cout<<"Debited amount"<<balance<<"Total available Balance is: "<<amount<<endl;
        }
    }
    int getBalance(){
        return amount;
    }
};


//Abstraction
class Bike{
public:
    virtual int maxspeed()=0;
    virtual int getmilleage()=0;
};

class MountainBike: public Bike{
public:
    int maxspeed(){
        return 160;
    }
    int getmilleage(){
        return 30;
    }
};

class NormalBike: public Bike{
public:
    int maxspeed(){
        return 120;
    }
    int getmilleage(){
        return 40;
    }
};

int main(){
    // cout<<add(2,3)<<endl;
    // cout<<add(2.1,3.4)<<endl;
    // Animal *a;
    // Dog d;
    // a=&d;
    // a->sound();
    Bike *b=new MountainBike();
    cout<<b->getmilleage();
}