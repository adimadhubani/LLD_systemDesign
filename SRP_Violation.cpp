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
    const vector<Product*>& getproducts(){
        return products;
    }

    double calculatetotal(){
        double total=0;
        for(auto p:products){
            total=total+p->price;
        }
        return total;
    }

    void printrecipt(){
        cout<<"Recipt:"<<endl;
        for(auto p:products){
            cout<<p->name<<" "<<p->price<<endl;
        }
        cout<<"Total: "<<calculatetotal()<<endl;
    }

    void savetodatabase(){
        cout<<"Saving to database..."<<endl;
    }
};

int main(){
    Product* p1=new Product("Book",10);
    Product* p2=new Product("Pen",5);

    ShoppingCart cart;
    cart.addproducts(p1);
    cart.addproducts(p2);

    cart.printrecipt();
    cart.savetodatabase();

    return 0;
}

