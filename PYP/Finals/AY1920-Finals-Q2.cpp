#include <iostream>

using namespace std;

class Car 
{
protected:
    virtual int top_speed() 
    {
        return 120;
    }
public:
    virtual void drive(int speed) 
    {
        speed = min(speed, top_speed());
        cout << "Vroom! " << speed << " km/h" << endl;
    }
};

class SportsCar : public Car 
{
protected:
    bool nitro = false; int top_speed() 
    {
        int t = Car::top_speed();
        if (nitro) t += 100;
        return t;
    }
public:
    virtual void toggle_nitro() 
    {
        nitro = !nitro;
    }
};

class PoliceCar : public SportsCar 
{
    bool siren = false;
public:
    virtual void toggle_siren() 
    {
        siren = !siren;
        nitro = nitro and siren; 
    }
    virtual void toggle_nitro() 
    { 
        nitro = !nitro and siren;
    }
    void drive(int speed) 
    { 
        if (siren) 
        {
            cout << "Bee Do Bee Do. ";
        }
        SportsCar::drive(speed);
    }
};

int main()
{
    PoliceCar pc;
    pc.drive(200);
    pc.toggle_nitro();
    pc.drive(200);
    pc.toggle_siren();
    pc.drive(200);
    pc.toggle_nitro();
    pc.drive(200);
    pc.toggle_siren();
    pc.drive(200);
}