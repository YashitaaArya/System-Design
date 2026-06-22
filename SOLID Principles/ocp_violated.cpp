#include<iostream>
#include "srp_followed.cpp"
using namespace std;

// Voiding OCP
class DBStorage{
    private:
        ShoppingCart* cart;
    public:
        DBStorage(ShoppingCart* cart){
            this->cart = cart;
        }
        void saveToSQLDB(){
            cout << "Saving shopping cart to SQL DB..." << endl;
        }
        void saveToMongoDB(){
            cout << "Saving shopping cart to Mongo DB..." << endl;
        }
        void saveToFile(){
            cout << "Saving shopping cart to File..." << endl;
        }
};
int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 999.99));
    cart->addProduct(new Product("Headphones", 199.99));
    cart->addProduct(new Product("Mouse", 49.99));
    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    DBStorage* db = new DBStorage(cart);
    db->saveToSQLDB();

    // db->saveToDatabase();
    // return 0;
    return 0;
}