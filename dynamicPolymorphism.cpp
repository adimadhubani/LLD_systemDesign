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
    void stopEngine(){
        if(isEngineon){
            isEngineon=false;
            currentspeed=0;
            cout<<brand<<" "<<model<<" engine stopped."<<endl;
        }
    }
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual ~Car() {};
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
    ~ManualCar(){}
};

class ElectricCar:public Car{
    private:
     int batteryLevel;
    public:
    ElectricCar(string m,string b):Car(m,b){
        batteryLevel=100;
    }
   void accelerate(){
        if(isEngineon){
            currentspeed+=15;
            batteryLevel-=5;
            cout<<brand<<" "<<model<<" accelerated to "<<currentspeed<<" km/h. Battery level: "<<batteryLevel<<"%."<<endl;
        }
    }

    void brake(){
        if(isEngineon && currentspeed>0){
            currentspeed-=15;
            cout<<brand<<" "<<model<<" decelerated to "<<currentspeed<<" km/h. Battery level: "<<batteryLevel<<"%."<<endl;
        }
    }
    ~ElectricCar(){}
};

int main(){
    Car* myManualCar=new ManualCar("Model S","Tesla");
    Car* myElectricCar=new ElectricCar("Leaf","Nissan");

    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

    cout<<endl;

    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myManualCar;
    delete myElectricCar;

    return 0;
}