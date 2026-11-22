#include<bits/stdc++.h>
using namespace std;

class Character {
    public:
        virtual string getAbilities() const = 0;
        virtual ~Character() {}
};

class Mario : public Character {
    public:
    string getAbilities() const override {
        return "Mario";
    }
};

class CharacterDecorate : public Character {
    protected:
        Character* character;

    public:
        CharacterDecorate(Character* c){
            this->character = c;
        }
};

class HeightUp : public CharacterDecorate {
    public:
        HeightUp(Character* c) : CharacterDecorate(c) {}

        string getAbilities() const override{
            return character->getAbilities() + " with HeightUp !!!";
        }
};

class GunPowerUp : public CharacterDecorate {
    public:
        GunPowerUp(Character* c) : CharacterDecorate(c) {}

        string getAbilities() const override{
            return character->getAbilities() + " with GunPowerUp !!!";
        }
};

class StarPowerUp : public CharacterDecorate {
    public:
        StarPowerUp(Character* c) : CharacterDecorate(c) {}

        string getAbilities() const override{
            return character->getAbilities() + " with StarPowerUp !!!";
        }

        ~StarPowerUp(){
            cout << "Destroying Star Abilities !!!"<<endl;
        }
};

int main(){

    Character* mario = new Mario();
    cout << "Basic Charater : " << mario->getAbilities() << endl;

    mario = new HeightUp(mario);
    cout << "After Height Up : " << mario->getAbilities() << endl;

    mario = new GunPowerUp(mario);
    cout << "After GunPower Up : " << mario->getAbilities() << endl;

    mario = new StarPowerUp(mario);
    cout << "After StarPower Up : " << mario->getAbilities() << endl;

    delete mario;
    return 0;
}