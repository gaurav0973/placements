/*
SOLID
    O -> Open/Closed Principle
what it does ?
    - software entities (classes, modules, functions, etc.) should be open for extension but closed for modification
    - 
    - I can add new functionality without changing existing code
How to achieve this ?
    - use inheritance and interface(abstract classes) + polymorphism
    - create new classes that extend existing ones
    - implement new functionality in the derived classes
*/

#include<bits/stdc++.h>
using namespace std;

class Product{
    private:
        string name;
        double price;
    public:

        Product(string n, double p){
            this->name = n;
            this->price = p;
        }
        int getPrice(){
            return this->price;
        }
        string getName(){
            return this->name;
        }
};

class ShoppingCart{
    private:
        vector<Product*> products;
    public:
        void addProducts(Product *p){
            products.push_back(p);
        }

        auto getProducts(){
            return products;
        }
        double calculateTotalPrice(){
            double price = 0;
            for(auto &p : products){
                price += p->getPrice();
            }
            return price;
        }
    
};

class ShoppingCartPrinter {
private:
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto& p : cart->getProducts()) {
            cout << p->getName() << " - Rs " << p->getPrice() << endl;
        }
        cout << "Total: Rs " << cart->calculateTotalPrice() << endl;
    }
};

class PersistenceDB {
private:
    ShoppingCart* cart; 

public:
    virtual void save(ShoppingCart* cart) = 0; // pure virtual function
};

class MySQLPersistence : public PersistenceDB {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to MySQL database...\n";
        // Logic to save the cart to MySQL database
    }
};

class MongoDBPersistence : public PersistenceDB {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to MongoDB database...\n";
        // Logic to save the cart to MongoDB database
    }
};

class FilePersistence : public PersistenceDB {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to file...\n";
        // Logic to save the cart to a file
    }
};


int main(){
    Product *p1 = new Product("Laptop", 10000);
    Product *p2 = new Product("Keyboard", 400);
    Product *p3 = new Product("Mouse", 7564);

    ShoppingCart *cart = new  ShoppingCart();
    cart->addProducts(p1);
    cart->addProducts(p2);
    cart->addProducts(p3);

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    

    return 0;
}