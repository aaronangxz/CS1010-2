#include <iostream>
#include <vector>
using namespace std;

class Animal {
private:
    string _name; // e.g. Cow
    string _sound; // e.g. Moo

public:
    Animal()
    {

    }

    Animal(string name, string sound) 
    {
        _name = name;
        _sound = sound;
    }
    string getName() { return _name; }
    string getSound() { return _sound; }
};

class Flyer : public Animal {
private:
    string _name;
    string _sound;
    bool _isFlying;
public:
    Flyer(string name, string sound): _name(name), _sound(sound), _isFlying(true) {}

    string getSound()   
    {
        if(_isFlying) return "flap";
        else return Animal::getSound();
    }
    bool isFlying()
    {
        if(_isFlying) return true;
        return false;
    }

    void fly() { _isFlying = true; }
    void stop() { _isFlying = false; }
};

class Glider : public Flyer {
private:
    bool _isGliding;
public:
    Glider(string name, string sound): Flyer(name, sound), _isGliding(false) {}

    void glide() { if(isFlying()) _isGliding = true; }

    void stop() { Flyer::stop(); _isGliding = false; }

    string getSound() {
    if(_isGliding) return "woosh";
    else return getSound();
    }
};


class NewMcDonald {
private:
    vector<Animal*> _farm; // New McDonald had a farm (still has now)

public:
NewMcDonald() 
{
    fillThisFarm();
    /* TODO: Create your farm, an Animal* vector */
}
~NewMcDonald() 
{
     _farm.clear();
    /* TODO: New McDonald has no (more) farm... */
}
void sing() {
    for (Animal *animal : _farm) 
    {
        cout << "Old McDonald had a farm, E-I-E-I-O\n";
        cout << "And on his farm he had a " << animal->getName() << ", E-I-E-I-O\n";
        cout << "With a " << animal->getSound() << " " << animal->getSound() << " here and a " << animal->getSound() << " " << animal->getSound() << " there\n";
        cout << animal->getSound() << " here" << animal->getSound() << " there, everywhere " << animal->getSound() << " " << animal->getSound() << endl;
        cout<< "Old McDonald had a farm, E-I-E-I-O\n\n";
    }
}

void fillThisFarm() {
    _farm.push_back(new Flyer("Parrot", "squark"));
    _farm.push_back(new Animal("Cow", "moo"));
    _farm.push_back(new Flyer("Mosquito", "buzz"));
    ((Flyer*)_farm[2])->fly();
    _farm.push_back(new Animal("Sheep", "mehh"));
    _farm.push_back(new Animal("Fish", "blurp"));
    }
};

int main() 
{
    NewMcDonald().sing();
}