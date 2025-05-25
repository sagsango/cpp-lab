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
        ~Factory() {
            cout << "Factory destroyed." << endl;
        }
        Vehicle* createVehicle(vehicalType type, string plate, string color) {
            switch (type) {
                case BICYCLE:
                    return new Bicycle(plate, color);
                case CAR:
                    return new Car(plate, color);
                default:
                    return nullptr;
            }
        }
};

int main() {
    Factory factory;
    Vehicle* vehicle1 = factory.createVehicle(BICYCLE, "1234", "Red");
    vehicle1->canDrive(5);
    vehicle1->canDrive(15);
    delete vehicle1;

    Vehicle* vehicle2 = factory.createVehicle(CAR, "5678", "Blue");
    vehicle2->canDrive(2);
    vehicle2->canDrive(20);
    delete vehicle2;

    return 0;
}


