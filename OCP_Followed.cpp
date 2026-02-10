#include<iostream>
#include<string>
using namespace std;

class Product{
    public:
    string name;
    double price;
    public:
    Product(string n,double p){
        this->name=n;
        this->price=p;
    }
};

class ShoppingCart{
    private:
    vector<Product*> products;

    public:

    void addproducts(Product* p){
        products.push_back(p);
    }

    vector<Product*> getproducts(){
        return products;
    }

    double calculatetotal(){
        double total=0;
        for(auto p:products){
            total=total+p->price;
        }
        return total;
    }


};

class Recipt{
    private:
    ShoppingCart* cart;

    public:

    Recipt(ShoppingCart* c){
        this->cart=c;
    }

    void printrecipt(){
        cout<<"Recipt:"<<endl;
        for(auto p:cart->getproducts()){
            cout<<p->name<<" "<<p->price<<endl;
        }
        cout<<"Total: "<<cart->calculatetotal()<<endl;
    }

};

class Presistence{
    private:
    ShoppingCart* cart;

    public:
    virtual void savetodatabase(ShoppingCart* c)=0;
    
};

class sqlPresistence:public Presistence{
    public:
    void savetodatabase(ShoppingCart* c) override {
        cout<<"Saving to SQL database..."<<endl;
    }

};

class MongoPresistence:public Presistence{
    public:
    void savetodatabase(ShoppingCart* c) override {
        cout<<"Saving to MongoDB database..."<<endl;
    }

};

class FilePresistence:public Presistence{
    public:
    void savetodatabase(ShoppingCart* c) override {
        cout<<"Saving to file..."<<endl;
    }

};

int main(){
    Product* p1=new Product("Book",10); 
    Product* p2=new Product("Pen",5);

    ShoppingCart* cart=new ShoppingCart();
    cart->addproducts(p1);
    cart->addproducts(p2);

    Recipt* recipt=new Recipt(cart);
    recipt->printrecipt();

    Presistence* sqldb=new sqlPresistence();
    sqldb->savetodatabase(cart);

    Presistence* mongodb=new MongoPresistence();
    mongodb->savetodatabase(cart);

    Presistence* filedb=new FilePresistence();
    filedb->savetodatabase(cart);

        return 0;

    }

