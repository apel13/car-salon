#include "car.h"

#include <iostream>
#include <iomanip>
#include <random>
#include <array>
#include <experimental/array>

using namespace std;


Car::Car(std::string name, std::string color,
         double price, double max_speed, double weight)
        : _id(_gID++), _name(move(name)), _color(move(color))
        , _price(price), _max_speed(max_speed), _weight(weight) {}

uint32_t Car::getID() const {
    return _id;
}

const string &Car::getName() const {
    return _name;
}

const string &Car::getColor() const {
    return _color;
}

double Car::getPrice() const {
    return _price;
}

double Car::getMaxSpeed() const {
    return _max_speed;
}

double Car::getWeight() const {
    return _weight;
}

void Car::setName(const string &name) {
    _name = name;
}

void Car::setColor(const string &color) {
    _color = color;
}

void Car::setMaxSpeed(double maxSpeed) {
    _max_speed = maxSpeed;
}

void Car::setWeight(double weight) {
    _weight = weight;
}


uint32_t Car::_gID = 1000;

std::shared_ptr<Car> Car::generateCar() {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    static std::uniform_real_distribution<> price_dis(1'000'000.0, 10'000'000.0);
    static std::uniform_real_distribution<> speed_dis(100.0, 400.0);
    static std::uniform_real_distribution<> weight_dis(800.0, 2500.0);

    static const auto names =
            experimental::make_array("Toyota", "Nissan", "BMW", "Porsche", "Ford", "Audi");
    static const auto colors =
            experimental::make_array("Wenge", "Red", "Blue", "Green");

    return std::make_shared<Car>(
            names[std::rand() % names.size()],
            colors[std::rand() % colors.size()],
            price_dis(gen),
            speed_dis(gen),
            weight_dis(gen)
    );
}

ostream &operator<<(ostream &os, const Car &car) {
    os << fixed << setprecision(2);
    return os
            << "["
            << setw(4) << left << car.getID() << ", "
            << setw(7) << left << car.getName() << ", "
            << setw(9) << left << car.getColor() << ", "
            << setw(9) << left << car.getPrice() << ", "
            << setw(6) << left << car.getMaxSpeed() << ", "
            << setw(7) << left << car.getWeight()
            << "]";
}
