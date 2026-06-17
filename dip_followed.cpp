#include<iostream>
using namespace std;
// abstract class for database
class Database{
    public:
        virtual void save(string data)=0; // pure virtual function
};
// subclass
class MySQLDB : public Database{
    public:
        void save(string data) override{
            cout << "Executing SQL Query: INSERT INTO user VALUES (" << data << ")" << endl;
        }
};
// subclass
class MongoDB : public Database{
    public:
        void save(string data) override{
            cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
        }
};

class UserService{
    private:
        Database* db; //dependency injection
    public:
        UserService(Database* database) : db(database){}
        void saveUser(string name){
            db->save(name);
        }
};

int main(){
    MySQLDB sqlDB;
    MongoDB mongoDB;
    UserService userService1(&sqlDB);
    userService1.saveUser("Yashitaa");

    UserService userService2(&mongoDB);
    userService2.saveUser("Ashu");
    return 0;
}