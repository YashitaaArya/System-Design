#include<iostream>
#include "srp_followed.cpp"
using namespace std;

// abstract class for persistence
class Persistence{
    private:
        ShoppingCart* cart;
    public:
        virtual void save(ShoppingCart* cart)=0; //pure virtual function
};

class SQLPersistence : public Persistence{
    public:
        void save(ShoppingCart* cart) override{
            cout << "Saving shopping cart to SQL DB..." << endl;
        }
};

class MongoPersistence : public Persistence{
    public:
        void save(ShoppingCart* cart) override{
            cout << "Saving shopping cart to Mongo DB..." << endl;
        }
};

class FilePersistence : public Persistence{
    public:
        void save(ShoppingCart* cart) override{
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

    Persistence* sql = new SQLPersistence();
    sql->save(cart);
    Persistence* mongo = new MongoPersistence();
    mongo->save(cart);
    Persistence* file = new FilePersistence();
    file->save(cart);

    // DBStorage* db = new DBStorage(cart);
    // db->saveToSQLDB();

    return 0;
}