#include <iostream>
#include<string>
using namespace std;

class Car{
    public:
    virtual void startEngine()=0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    virtual ~Car() {};
};


class SportCar:public Car{
    public:
    string brand;
    string model;
    bool isEngineon;
    int currentspeed;
    int currentgear;

    SportCar(string b,string m){
        this->brand=b;
        this->model=m;
        isEngineon=false;
        currentspeed=0;
        currentgear=0;
    }

    void startEngine(){
        isEngineon=true;
        cout<<brand<<" "<<model<<" engine started."<<endl;
    }
    void shiftGear(int gear){
        if(isEngineon){
            currentgear=gear;
            cout<<brand<<" "<<model<<" shifted to gear "<<gear<<"."<<endl;
        }

    }

    void accelerate(){
        if(isEngineon){
            currentspeed+=10;
            cout<<brand<<" "<<model<<" accelerated to "<<currentspeed<<" km/h."<<endl;
        }
    }
    void brake(){
        if(isEngineon && currentspeed>0){
            currentspeed-=10;
            cout<<brand<<" "<<model<<" decelerated to "<<currentspeed<<" km/h."<<endl;
        }
    }
    void stopEngine(){
        if(isEngineon){
            isEngineon=false;
            currentspeed=0;
            currentgear=0;
            cout<<brand<<" "<<model<<" engine stopped."<<endl;
        }
    }
};

int main(){
    
    SportCar* myCar=new SportCar("Ferrari","488 Spider");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    delete myCar;
    return 0;
    }

