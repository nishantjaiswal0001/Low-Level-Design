#include<bits/stdc++.h>
using namespace std;

class Shirt{
public:
string brand,model;
int size;
   Shirt(string brand,string model,int size){
       this->brand=brand;
       this->model=model;
       this->size=size;
   }
};

class WeddingShirt: public Shirt{
public:  
     WeddingShirt(string brand,string model,int size): Shirt(brand,model,size){

     }
     void getDetails(){
      cout<<"Shirt Brand is: "<<brand<<endl;
      cout<<"Shirt Model is: "<<model<<endl;
      cout<<"Shirt Size is: "<<size<<endl;
   }
};

class Animal{
public:
    virtual void sound(){
       cout<< "Animal makes sound"<<endl;
    }
};

class Dog: public Animal{
public:
    void sounds(){  //will give answer Animal makes sound as sounds!=sound
        cout<<"Dog Barks"<<endl;
    }
    void sound() override{
        cout<<"Dog Barks"<<endl;
    }
};

class Cat: public Animal{
public:
    void sound() override{
        cout<<"Cat Meows"<<endl;
    }
};

int main(){
  Animal* a;
  Dog d;
  a=&d;
  a->sound();
  Cat c;
  a=&c;
  a->sound();
}