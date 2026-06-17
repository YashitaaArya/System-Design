#include<iostream>
using namespace std;

class MySQLDB{
    public:
        void saveToSQL(string data){
            cout << "Executing SQL Query: INSERT INTO user VALUES (" << data << ")" << endl;
        }
};

class MongoDB{
    public:
        void saveToMongo(string data){
            cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
        }
};

class UserService{
    private:
        MySQLDB sqlDB;
        MongoDB mongoDB;
    public:
        void saveUserToSQL(string name){
            sqlDB.saveToSQL(name);
        }
        void saveUserToMongo(string name){
            mongoDB.saveToMongo(name);
        }
};

int main(){
    UserService userService;
    userService.saveUserToSQL("Alice");
    userService.saveUserToMongo("Bob");
    return 0;
}