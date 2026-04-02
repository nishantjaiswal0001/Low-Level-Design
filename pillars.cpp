#include<bits/stdc++.h>
using namespace std;

class Payment{
public:
  virtual void pay()=0;  //Abstraction, “Any class that inherits Payment MUST implement pay()”
};

class UPI: public Payment{
public:
   void pay(){
    cout<<"UPI Payment is processing\n";
   }
};

class Card: public Payment{
public:
   void pay(){
    cout<<"Card Payment is processing\n";
   }
};


int main(){
Payment* p=new UPI();
p->pay();
Payment* q=new Card();
q->pay();
}