#include<iostream>
#include<string>
using namespace std;

class account{
    public:
    string name;

    public:
    account(string n){
        this->name=n;
        cout<<"Account created for: "<<name<<endl;
        
    }

};

class depositonlyaccount:public account{
   public:
   depositonlyaccount(string n):account(n){}

   virtual void deposit(double amount)=0;
};

class withdrawaccount:public depositonlyaccount{
    public:
    withdrawaccount(string n):depositonlyaccount(n){}

    virtual void withdraw(double amount)=0;
};

class savingaccount:public withdrawaccount{
    private:
    double balance;

    public:
    savingaccount(string n):withdrawaccount(n){
        this->balance=0;
    }

    void deposit(double amount) override{
        balance+=amount;
        cout<<"account holder: "<<name<<" Deposited: "<<amount<<". Current Balance: "<<balance<<endl;
    }

    void withdraw(double amount) override{
        if(amount<=balance){
            balance-=amount;
            cout<<"account holder: "<<name<<" Withdrew: "<<amount<<". Current Balance: "<<balance<<endl;
        }else{
            cout<<"Insufficient funds. Current Balance: "<<balance<<endl;
        }
    }
};

   class currentaccount:public withdrawaccount{
    private:
    double balance;

    public:
    currentaccount(string n):withdrawaccount(n){
        this->balance=0;
    }

    public:
    void deposit(double amount) override{
        balance+=amount;
        cout<<"account holder: "<<name<<" Deposited: "<<amount<<". Current Balance: "<<balance<<endl;
    }

    void withdraw(double amount) override{
        if(amount<=balance){
            balance-=amount;
            cout<<"account holder: "<<name<<" Withdrew: "<<amount<<". Current Balance: "<<balance<<endl;
        }else{
            cout<<"Insufficient funds. Current Balance: "<<balance<<endl;
        }
    }
   };

   class fixeddepositaccount:public depositonlyaccount{
    private:
    double balance;

    public:
    fixeddepositaccount(string n):depositonlyaccount(n){
        this->balance=0;
    }

    void deposit(double amount) override{
        balance+=amount;
        cout<<"account holder: "<<name<<" Deposited: "<<amount<<". Current Balance: "<<balance<<endl;
    }
   };

   class bankclient{
    private:
    vector<depositonlyaccount*> depositaccounts;
    vector<withdrawaccount*> withdrawaccounts;

    public:
     bankclient(vector<depositonlyaccount*> accs,vector<withdrawaccount*> waccs){
        this->depositaccounts=accs;
        this->withdrawaccounts=waccs;
     }

     void processtransaction(){
        for(withdrawaccount* acc:withdrawaccounts){
            acc->deposit(200);
            acc->withdraw(100);
        }

        for(depositonlyaccount* acc:depositaccounts){
            acc->deposit(500);
        }
     }

   };


   int main(){
    vector<depositonlyaccount*> depositaccounts;
    vector<withdrawaccount*> withdrawaccounts;
    savingaccount* sa=new savingaccount("Alice");
    currentaccount* ca=new currentaccount("Bob");
    fixeddepositaccount* fda=new fixeddepositaccount("Charlie");

   withdrawaccounts.push_back(sa);
    withdrawaccounts.push_back(ca);
    depositaccounts.push_back(fda);

    bankclient* client=new bankclient(depositaccounts,withdrawaccounts);

        client->processtransaction();

    return 0;
   }


