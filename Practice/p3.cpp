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
// class Bank{
// private:
// int amount;
// public: 
//     Bank(int amount){
//         this->amount=amount;
//     }
//     void credit(int balance){
//         amount+=balance;
//         cout<<"Credited amount"<<balance<<"Total available Balance is: "<<amount<<endl;
//     }
//     void debit(int balance){
//         if(amount<balance) cout<<"Insufficient Balance"<<endl;
//         else{
//             amount-=balance;
//             cout<<"Debited amount"<<balance<<"Total available Balance is: "<<amount<<endl;
//         }
//     }
//     int getBalance(){
//         return amount;
//     }
// };


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

class Singleton{
private:
  static Singleton* instance;
  Singleton(){
      cout<<"Singleton called hua\n";
  }
public:
  static Singleton* getinstance(){
     if(instance==nullptr){
        instance=new Singleton();
     }
     return instance;
  }
};

Singleton* Singleton::instance=nullptr;  //:: is the scope resolution operator
int x=20;



class Account{
private:
int acnum,balance;
string name;
public:
    Account(string name,int acnum){
      this->name=name;
      this->acnum=acnum;
      this->balance=0;
   }
   void showaccdetails(){
       cout<<name<<endl;
       cout<<acnum<<endl;
       cout<<balance<<endl;
   }
};

class Bank{
private:
vector<Account* > accounts;
public:
string name;
   Bank(string name){
       this->name=name;
   }
   void openAccount(Account* acc){
      accounts.push_back(acc);
   }
   void showdetails(){
      for(auto acc: accounts){
          acc->showaccdetails();
      }
   }
};


int main(){
    // cout<<add(2,3)<<endl;
    // cout<<add(2.1,3.4)<<endl;
    // Animal *a;
    // Dog d;
    // a=&d;
    // a->sound();
    // Bike *b=new MountainBike();
    // cout<<b->getmilleage();
    // Singleton *s1=Singleton::getinstance();
    // Singleton *s2=Singleton::getinstance();
    // cout<<(s1==s2);
    // int x=10;
    // cout<<::x;
    Bank* b1=new Bank("SBI");
    Bank* b2=new Bank("HDFC");
    // Bank b2("HDFC");
    Account* a1=new Account("Nishant",3620030);
    Account* a2=new Account("Vishal",3620032);
    b1->openAccount(a1);
    b2->openAccount(a2);
    a1->showaccdetails();
    a2->showaccdetails();
}