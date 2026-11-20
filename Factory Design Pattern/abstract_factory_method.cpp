#include<iostream>

using namespace std;

// burger products-----
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

class BasicWheatBurger : public Burger {
    public:
        void prepare() override {
            cout << "preparing basic wheat burger ..." << endl;
        }
};

class StandardWheatBurger : public Burger {
    public:
        void prepare() override {
            cout << "preparing standard wheat burger ..." << endl;
        }
};

class PremiumWheatBurger : public Burger {
    public:
        void prepare() override {
            cout << "preparing premium wheat burger ..." << endl;
        }
};

// garlic bread products -----
class GarlicBread {
    public:
        virtual void prepare() = 0;
        virtual ~GarlicBread() {}
};

class BasicGarlicBread : public GarlicBread {
    public:
        void prepare() override {
            cout << "preparing basic garlic bread ..." << endl;
        }
};

class StandardGarlicBread : public GarlicBread {
    public:
        void prepare() override {
            cout << "preparing standard galic bread ..." << endl;
        }
};

class PremiumGarlicBread : public GarlicBread {
    public:
        void prepare() override {
            cout << "preparing premium garlic bread ..." << endl;
        }
};

class BasicWheatGarlicBread : public GarlicBread {
    public:
        void prepare() override {
            cout << "preparing basic wheat garlic bread ..." << endl;
        }
};

class StandardWheatGarlicBread : public GarlicBread {
    public:
        void prepare() override {
            cout << "preparing standard wheat garlic bread ..." << endl;
        }
};

class PremiumWheatGarlicBread : public GarlicBread {
    public:
        void prepare() override {
            cout << "preparing premium wheat garlic bread ..." << endl;
        }
};

class BurgerFactory {
    public:
        virtual Burger* createBurger(string& type) = 0;
        virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class SinghBurger : public BurgerFactory {
    public:
        Burger* createBurger(string& type)
        {
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

        GarlicBread* createGarlicBread(string& type)
        {
            if(type == "basic")
                return new BasicGarlicBread();
            else if(type == "standard")
                return new StandardGarlicBread();
            else if(type == "premium")
                return new PremiumGarlicBread();
            else
            {
                cout << "invalid input ..." << endl;
                return nullptr;
            }
        }
};

class kingBurger : public BurgerFactory {
    public:
        Burger* createBurger(string& type)
        {
            if(type == "basic")
                return new BasicWheatBurger();
            else if(type == "standard")
                return new StandardWheatBurger();
            else if(type == "premium")
                return new PremiumWheatBurger();
            else
            {
                cout << "invalid input ..." << endl;
                return nullptr;
            }
        }

        GarlicBread* creaetGarlicBread(string& type)
        {
            if(type == "basic")
                return new BasicWheatGarlicBread();
            else if(type == "standard")
                return new StandardWheatGarlicBread();
            else if(type == "premium")
                return new PremiumWheatGarlicBread();
            else
            {
                cout << "invalid input ..." << endl;
                return nullptr;
            }
        }
};

int main(){

    string type = "premium";

    BurgerFactory* newBurgerFactory = new SinghBurger();

    GarlicBread* bg = newBurgerFactory->createGarlicBread(type);

    bg->prepare();

    return 0;
}