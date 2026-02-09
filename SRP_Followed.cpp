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

class Database{
    private:
    ShoppingCart* cart;

    public:
    Database(ShoppingCart* c){
        this->cart=c;
    }

    void savetodatabase(){
        cout<<"Saving to database..."<<endl;
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

    Database* db=new Database(cart);
    db->savetodatabase();
        return 0;
}