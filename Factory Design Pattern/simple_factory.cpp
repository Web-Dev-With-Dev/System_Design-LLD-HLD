#include<iostream>

using namespace std;

class Burger {
    public:
        virtual void prepare() = 0;
        virtual ~Burger() {}
};

class BasicBurger : public Burger {
    public:
        void prepare() override {
            cout << "preparing basic burger ..." << endl;
        }
};

class StandardBuger : public Burger {
    public:
        void prepare() override {
            cout << "preparing standard burger ..." << endl;
        }
};

class PremiumBurger : public Burger {
    public:
        void prepare() override {
            cout << "preparing premium burger ..." << endl;
        }
};

class BurgerFactory {
    public:
        Burger* createBurger(string& type){
            if(type == "basic")
                return new BasicBurger();
            else if(type == "standard")
                return new StandardBuger();
            else if(type == "premium")
                return new PremiumBurger();
            else
            {
                cout << "invalid input ..." << endl;
                return nullptr;
            }
        }
};

int main(){

    string type = "standard";

    BurgerFactory* newBurgerFactory = new BurgerFactory();

    Burger* bg = newBurgerFactory->createBurger(type);

    bg->prepare();

    return 0;
}