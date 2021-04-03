#include <iostream>
#include <vector>
using namespace std;

class Animal {
private:
    string _species;
    string _sound;
public:
    Animal(string species, string sound)
    {
        this->_species = species;
        this->_sound = sound;
    }
    string get_species() { return _species; }
    string get_sound() { return _sound; }
};

class OldMcDonald {
private:
    vector<Animal*> _farm; // Old McDonald had a farm (still has now)

public:
    OldMcDonald() {
        _farm.push_back(new Animal("Cow","Moo"));
        _farm.push_back(new Animal("Dog","Woof"));
        _farm.push_back(new Animal("Duck","Quack"));
    }
    ~OldMcDonald() {
        _farm.clear();
    }
    
    // void sing() {
    //     for (int i=0; i<_farm.size(); i++) {
    //         cout << "Old McDonald had a farm, E-I-E-I-O\n";
    //         cout << "And on his farm he had a " << _farm[i]->get_species() << ", E-I-E-I-O" << endl;
    //         cout << "With a " << _farm[i]->get_sound() << " " << _farm[i]->get_sound()<< " here and a " << _farm[i]->get_sound() << " " << _farm[i]->get_sound() << " there" << endl;
    //         cout << _farm[i]->get_sound() << " here " << _farm[i]->get_sound() << " there, everywhere " << _farm[i]->get_sound() << " " << _farm[i]->get_sound() << endl;
    //         cout<< "Old McDonald had a farm, E-I-E-I-O" << endl << endl;
    //     }
    // }
    void sing() {
        for (int i=0; i<_farm.size(); i++) {
            cout << "Old McDonald had a farm, E-I-E-I-O\n";
            cout << "And on his farm he had a " << _farm[i]->get_species() << ", E-I-E-I-O\n";
            cout << "With a " << _farm[i]->get_sound() << " " << _farm[i]->get_sound()<< " here and a " << _farm[i]->get_sound() << " " << _farm[i]->get_sound() << " there\n";
            cout << _farm[i]->get_sound() << " here " << _farm[i]->get_sound() << " there, everywhere " << _farm[i]->get_sound() << " " << _farm[i]->get_sound() << "\n";
            cout<< "Old McDonald had a farm, E-I-E-I-O\n\n";
        }
    }
};

int main() 
{
    OldMcDonald().sing();
}