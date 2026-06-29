#include<bits/stdc++.h>
using namespace std;

//Strategy Design Pattern

// //Without Strategy Pattern
// class Vehicle{
// public:
//     virtual void drive(){
//         cout<<"Normal Driving"<<endl;
//     }

//     virtual ~Vehicle(){}
// };

// class PassengerVehicle : public Vehicle{

// };

// class SportsVehicle : public Vehicle{
// public:
//     void drive() override{
//         cout<<"Special Driving"<<endl;
//     }
// };

// class OffRoadVehicle : public Vehicle{
// public:
//     void drive() override{
//         cout<<"Special Driving"<<endl;  //same code written twice if an other vehicle comes in future and needs special then again code copy
//     }
// };


//with Strategy Pattern
class DriveStrategy{
public:
   virtual void drive()=0;
   virtual ~DriveStrategy(){}
};

class NormalDrive: public DriveStrategy{
public:
   void drive() override{
      cout<<"Normal Driving"<<endl;
   }
};

class SpecialDrive: public DriveStrategy{
public:
   void drive() override{
      cout<<"Special Driving"<<endl;
   }
};

class Vehicle{
protected:
DriveStrategy *strategy;
public:
     Vehicle(DriveStrategy* obj){
        strategy=obj;
     }
     virtual void drive(){
        strategy->drive();
     }
     virtual ~Vehicle(){}
};

class Sportsvehicle: public Vehicle{
public:
    Sportsvehicle(): Vehicle(new SpecialDrive()){}
};

class Passengersvehicle: public Vehicle{
public:
    Passengersvehicle(): Vehicle(new NormalDrive()){}
};

class offroadvehicle: public Vehicle{
public:
    offroadvehicle(): Vehicle(new SpecialDrive()){}
};


//Singleton
class Singleton{
private:
   static Singleton* instance;
   Singleton(){
      cout<<"Singleton Constructor call hua\n";
   }
public:
   static Singleton* getinstance(){
      if(instance==nullptr){
         instance=new Singleton();
      }
      return instance;
   }
};

Singleton* Singleton::instance=nullptr;

int main(){
   // Vehicle* v1= new Sportsvehicle();
   // Vehicle* v2= new Passengersvehicle();
   // Vehicle* v3= new offroadvehicle();
   // v1->drive();
   // v2->drive();
   // v3->drive();
   Singleton *s1=Singleton::getinstance();
   Singleton *s2=Singleton::getinstance();
   cout<<(s1==s2);
}