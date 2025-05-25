#include <iostream>
#include <string>
using namespace std;

enum ageGroup {
    CHILD_AGE = 8,
    ADULT_AGE = 18,
    ELDER_AGE = 60
};

enum vehicalType {
    BICYCLE,
    CAR
};

class Vehicle {
    private:
        string plate;
        string color;
    public:
        virtual ~Vehicle() {
            cout << "Vehicle destroyed." << endl;
        }
        Vehicle(string plate, string color) : plate(plate), color(color) {
            cout << "Vehicle created." << endl;
        }
        virtual void canDrive(int age) = 0;
        
};

class Bicycle: public Vehicle {
    public:
        Bicycle(string plate, string color) : Vehicle(plate, color) {}
       ~Bicycle() {
            cout << "Bicycle destroyed." << endl;
        }
        void canDrive(int age) override {
            if (age >= ageGroup::CHILD_AGE) {
                cout << "Bicycle can be driven by anyone." << endl;
            } else {
                cout << "Bicycle can be driven by children." << endl;
            }
        }
};

class Car: public Vehicle {
    public:
        Car(string plate, string color) : Vehicle(plate, color) {}
        ~Car() {
            cout << "Car destroyed." << endl;
        }
        void canDrive(int age) override {
            if (age >= ageGroup::ADULT_AGE) {
                cout << "Car can be driven by adults." << endl;
            } else {
                cout << "Car cannot be driven by children." << endl;
            }
        }
};

class Factory {
    public:
        Factory() {
            cout << "Factory created." << endl;
        }
        virtual ~Factory() {
            cout << "Factory destroyed." << endl;
        }
        virtual Vehicle* createVehicle(string plate, string color) = 0;
};

class CarFactory: public Factory {
    public:
        CarFactory() {
            cout << "Car Factory created." << endl;
        }
        ~CarFactory() {
            cout << "Car Factory destroyed." << endl;
        }
        Vehicle * createVehicle(string plate, string color) override {
           //assert (type == vehicalType::CAR);
            return new Car(plate, color);
        }
};

class BicycleFactory: public Factory {
    public:
        BicycleFactory() {
            cout << "Bicycle Factory created." << endl;
        }
        ~BicycleFactory() {
            cout << "Bicycle Factory destroyed." << endl;
        }
        Vehicle * createVehicle(string plate, string color) override {
            //assert (type == vehicalType::BICYCLE);
            return new Bicycle(plate, color);
        }
};


int main() {
    Factory * factory = nullptr;

    factory = new CarFactory();
    Vehicle * car = factory->createVehicle("1234", "red");
    car->canDrive(2);
    car->canDrive(20);
    delete car;
    delete factory;

    factory = new BicycleFactory();
    Vehicle * bicycle = factory->createVehicle("5678", "blue");
    bicycle->canDrive(5);
    bicycle->canDrive(15);
    delete bicycle;
    delete factory;

    return 0;
}
