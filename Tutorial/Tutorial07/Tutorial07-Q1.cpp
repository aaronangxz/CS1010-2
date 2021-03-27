#include <iostream>
using namespace std;

class Person {
private:
    string _name;
    int _age;
    Person *mother;

public:
    Person(string name, int age) {
        _name = name;
        _age = age;
    }
    
    Person(string name, int age, Person person) {
        _name = name;
        _age = age;
        mother = &person;
    }
    
    string get_name() { return _name; }
    int get_age() { return _age; }
    // Person get_mother() { return *mother; }
};

int main() { // Note this is correct because we cannot have a main function on Coursemology.
    // Person a;
    Person sally("Sally", 32);
    Person thomas("Thomas", 6, sally);
    cout << sally.get_name() << " is the mother of " << thomas.get_name() << endl;
    cout << "their age difference is " << sally.get_age() - thomas.get_age() 
         << " years" << endl;
}
