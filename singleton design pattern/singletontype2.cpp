#include<iostream>
#include<mutex>

using namespace std;

class Singleton {
    private: 

        static Singleton* instance;

        Singleton() {
            cout << "Singleton constructore called. new object created !!!" << endl;
        }
    public:

        static Singleton* getInstance() {
            return instance;
        }
};

Singleton* Singleton::instance = new Singleton();

int main () {
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}