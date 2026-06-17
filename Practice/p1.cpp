#include<bits/stdc++.h>
using namespace std;

class Account{
private:
string name;
long long BankAccNum;
int BankBalance;
long long MobileNum;
public:
   Account(string name,long long MobileNum,long long BankAccNum){
      this->name=name;
      this->MobileNum=MobileNum;
      this->BankAccNum=BankAccNum;
      this->BankBalance=0;
   }
   void deposit(int balance){
       BankBalance+=balance;
   }
   void debit(int balance){
      if(BankBalance<balance){
        cout<<"Insufficient Balance"<<endl;
        return;
      }
      else BankBalance-=balance;
   }
   void showDetails(){
      cout<<"Customer name is: "<<name<<endl;
      cout<<"Bank Account Number is: "<<BankAccNum<<endl;
      cout<<"Bank Balance is: "<<BankBalance<<endl;
      cout<<"Registere Mobile Number is: "<<MobileNum<<endl;
      cout<<"<--------------------xxxxxxxxxxxxxxxxxx---------------------------->"<<endl;
   }
};
class Bank{
private:
  string BankName;
  vector<Account*> acc;
public:
  Bank(string BankName){
    this->BankName=BankName;
  }
  void OpenAccount(Account *a){
     acc.push_back(a);
     return;
  }
  
  void ShowAllAccounts(){
      for(auto a: acc) a->showDetails();
  }
};

int main(){

   Bank SBI("State Bank of India");
   Bank HDFC("HDFC Bank");
   Account *a1=new Account("Nishant Jaiswal",1234567890,362003012);
   Account *a2=new Account("Vishal Jaiswal",1234567891,362003013);
   Account *a3=new Account("Shiwani Jaiswal",1234567892,362003014);
   SBI.OpenAccount(a1);
   HDFC.OpenAccount(a2);
   SBI.OpenAccount(a3);
   a1->deposit(5000);
   a1->showDetails();
   SBI.ShowAllAccounts();
   a2->deposit(12000);
   a2->showDetails();
   a2->debit(5000);
   a3->debit(1000);
   HDFC.ShowAllAccounts();
   SBI.ShowAllAccounts();
}