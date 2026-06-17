#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Product{
    public:
        string name;
        double price;

        Product(string name, double price){
            this->name = name;
            this->price = price;
        }
};

class ShoppingCart{
    private:
        vector<Product*> products;
    public:
        void addProduct(Product* p){
            products.push_back(p);
        }
        const vector<Product*>& getProducts() {
            return products;
        }

        // 1. Calculate total price of products in the cart
        double calculateTotal(){
            double total = 0;
            for(auto p : products){
                total += p->price;
            }
            return total;
        }
};

class ShoppingCartPrinter{
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartPrinter(ShoppingCart* cart){
            this->cart=(cart);
        }
        
        void printInvoice(){
            cout << "Shopping Cart Invoice: " << endl;
            for(auto p : cart->getProducts()){
                cout << p->name << " - $" << p->price << endl;
            }
            cout << "Total: $" << cart->calculateTotal() << endl;
        }
};

class ShoppingCartStorage{
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartStorage(ShoppingCart* cart){
            this->cart=(cart);
        }
        
        void saveToDatabase(){
            cout << "Saving shopping cart to database..." << endl;
        }
};

// int main(){
//     ShoppingCart* cart = new ShoppingCart();

//     cart->addProduct(new Product("Laptop", 999.99));
//     cart->addProduct(new Product("Headphones", 199.99));
//     cart->addProduct(new Product("Mouse", 49.99));
//     ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
//     ShoppingCartStorage* db = new ShoppingCartStorage(cart);

//     printer->printInvoice();
//     db->saveToDatabase();
//     return 0;
// } 