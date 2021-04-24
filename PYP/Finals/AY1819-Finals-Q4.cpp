#include<iostream>
#include <vector>

using namespace std;

struct Order {
    int distance;
};

class Vehicle {
private:
    int reach;
public:
    vector<Order> completed_orders;
    Vehicle(int reach) 
    {
        this->reach = reach;
    }
    virtual bool deliver(Order order) 
    {
        if (reach < order.distance) 
        {
            cout << "Order is too far" << endl;
            return false;
        } else 
        {
            cout << "Order delivered" << endl;
            completed_orders.push_back(order);
            return true;
        }
    }
};
class Motorcycle : public Vehicle {
private:
    int fuel;
public:
    Motorcycle(int fuel) : Vehicle(fuel) 
    {
        this->fuel = fuel;
    }
    virtual bool deliver(Order order) 
    {
        if (fuel < order.distance) 
        {
            cout << "Not enough fuel" << endl;
            return false;
        } 
        else if (Vehicle::deliver(order)) 
        {
            fuel -= order.distance;
        }
    }
};  