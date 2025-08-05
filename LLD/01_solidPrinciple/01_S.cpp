/*
SOLID
    S -> Single Responsibility Principle
what it does ?
    - one class = one responsibility
    - a class should have only one reason to change
    - it promotes the use of composition over inheritance
How to use it ?
    - create classes that are focused on a single task or responsibility
    - avoid classes that handle multiple responsibilities
Example:
    class Product
        - price
        - name
    class ShoppingCart ❎vailating SRP
        - CalculateTotalPrice()  
        - PrintInvoice()
        - saveToDatabase()
Solution:
    class Product
        - price
        - name
    class ShoppingCart
        - CalculateTotalPrice()
    class InvoicePrinter
        - PrintInvoice()
    class DatabaseSaver
        - SaveToDatabase()
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


class ShoppingCartStorage {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartStorage(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};


int main(){
    Product p1("Laptop", 50000);
    Product p2("Phone", 20000);
    Product p3("Headphones", 3000);

    ShoppingCart cart;
    cart.addProducts(&p1);
    cart.addProducts(&p2);
    cart.addProducts(&p3);

    ShoppingCartPrinter printer(&cart);
    printer.printInvoice();

    ShoppingCartStorage storage(&cart);
    storage.saveToDatabase();

    return 0;
}