#include<iostream>
#include<string>
using namespace std;

class Car{
    protected:
     string brand;
     string model;
     bool isEngineon;
     int currentspeed;
    

    public:
    Car(string m,string b){
        this->model=m;
        this->brand=b;
        isEngineon=false;
        currentspeed=0;
    }

    void startEngine(){
        isEngineon=true;
        cout<<brand<<" "<<model<<" engine started."<<endl;
    }
    void shiftGear(int gear){
        if(isEngineon){
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
            cout<<brand<<" "<<model<<" engine stopped."<<endl;
        }
    }

    ~Car(){}

};

class ManualCar:public Car{
    private:
    int currentGear;

    public:
    ManualCar(string m,string b):Car(m,b){
        currentGear=0;
    }

    void shiftGear(int gear){
        if(isEngineon){
            currentGear=gear;
            cout<<brand<<" "<<model<<" shifted to gear "<<gear<<"."<<endl;
        }
    }
    ~ManualCar(){}

};

class ElectricCar:public Car{
    private:
    int batterylevel=0;
    public:
    ElectricCar(string m,string b):Car(m,b){
         batterylevel=100;
    }

    void chargeBattery(){
        batterylevel=100;
        cout<<brand<<" "<<model<<" battery fully charged."<<endl;
    }
    ~ElectricCar(){}

};

int main(){
    ManualCar* myManual=new ManualCar("Model S","Tesla");
    myManual->startEngine();
    myManual->shiftGear(1);
    myManual->accelerate();
    myManual->brake();
    myManual->stopEngine();
    delete myManual;


    ElectricCar* myElectric=new ElectricCar("Leaf","Nissan");
    myElectric->chargeBattery();
    myElectric->startEngine();
    myElectric->accelerate();
    myElectric->brake();
    myElectric->stopEngine();

    delete myElectric;

    return 0;

}

