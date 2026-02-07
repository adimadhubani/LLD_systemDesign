#include<iostream>
using namespace std;

class SportCar{
    private:
    string brand;
    string model;
    bool isEngineon;
    int currentspeed;
    int currentgear;
    string tyrecompany;
    public:
    SportCar(string b,string m){
        this->brand=b;
        this->model=m;
        isEngineon=false;
        currentspeed=0;
        currentgear=0;
        tyrecompany="DefaultTyres";
    }


    string gettyrecompany(){
        return tyrecompany;

    }
    int getcurrentspeed(){
        return currentspeed;
    }
    void settyrecompany(string tyre){
        tyrecompany=tyre;
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

    ~SportCar(){}
    

    };

    int main(){
        SportCar* myCar=new SportCar("Ferrari","488GTB");
        myCar->settyrecompany("Pirelli");
        myCar->gettyrecompany();
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