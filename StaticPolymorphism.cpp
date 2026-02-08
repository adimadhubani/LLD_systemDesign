#include<iostream>
#include<string>
using namespace std;

class ManualCar{
    private:
    string brand;
    string model;
    int currentGear;
    bool isEngineon;
    int currentSpeed;

    public:
    ManualCar(string m,string b){
        this->model=m;
        this->brand=b;
        isEngineon=false;
        currentSpeed=0;
        currentGear=0;
    }
    void startEngine(){
        isEngineon=true;
        cout<<brand<<" "<<model<<" engine started."<<endl;
    }
    void shiftGear(int gear){
        if(isEngineon){
            currentGear=gear;
            cout<<brand<<" "<<model<<" shifted to gear "<<gear<<"."<<endl;
        }
    }

    // StaticPolymorphism: Method Overloading
    void accelerate(){
        if(isEngineon){
            currentSpeed+=10;
            cout<<brand<<" "<<model<<" accelerated to "<<currentSpeed<<" km/h."<<endl;
        }
    }
    void accelerate(int increment){
        if(isEngineon){
            currentSpeed+=increment;
            cout<<brand<<" "<<model<<" accelerated to "<<currentSpeed<<" km/h."<<endl;
        }
    }
    void brake(){
        if(isEngineon && currentSpeed>0){
            currentSpeed-=10;
            cout<<brand<<" "<<model<<" decelerated to "<<currentSpeed<<" km/h."<<endl;
        }
    }
    void stopEngine(){
        if(isEngineon){
            isEngineon=false;
            currentSpeed=0;
            currentGear=0;
            cout<<brand<<" "<<model<<" engine stopped."<<endl;
        }
    }
    ~ManualCar(){}

};

int main(){
    ManualCar* mycar=new ManualCar("Mustang","Ford");;
    mycar->startEngine();
    mycar->shiftGear(1);
    mycar->accelerate();
    mycar->accelerate(20);
    mycar->brake();
    mycar->stopEngine();
    delete mycar;

    return 0;
}