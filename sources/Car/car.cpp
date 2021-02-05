#include "utils.h"
#include "car.h"


#include <iostream>
#include <iomanip>
#include <random>
#include <array>
#include <experimental/array>


using namespace std;


Car::Car(std::string name, std::string color,
         double price, double max_speed, double weight)
        : _id(_gID++), _name(move(name)), _color(move(color)), _price(price), _max_speed(max_speed), _weight(weight) {}

uint32_t Car::id() const {
    return _id;
}

const string &Car::name() const {
    return _name;
}

const string &Car::color() const {
    return _color;
}

double Car::price() const {
    return _price;
}

double Car::maxSpeed() const {
    return _max_speed;
}

double Car::weight() const {
    return _weight;
}

string &Car::name() {
    return _name;
}

string &Car::color() {
    return _color;
}

double &Car::price() {
    return _price;
}

double &Car::maxSpeed() {
    return _max_speed;
}

double &Car::weight() {
    return _weight;
}


uint32_t Car::_gID = 1000;

std::shared_ptr<Car> generateCar() {
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
            << setw(5) << left << car.id()
            << setw(8) << left << car.name()
            << setw(10) << left << car.color()
            << setw(11) << left << car.price()
            << setw(10) << left << car.maxSpeed()
            << setw(7) << left << car.weight()
            << "]";
}


namespace CarFilters {

    #define GEN_PREDICATE(Type, CarMethod)      \
        Type val;                               \
        is >> val;                              \
        auto op = parseOperator<Type>(str_op);  \
        return [op, val](const Car& car) {      \
            return op(car.CarMethod(), val);    \
        };

    std::function<bool(const Car &)> parseCondition(istringstream &is) {
        // takiye dela -_-
        // TODO take away
        string field, str_op;
        is >> field >> str_op;
        if (field == "id") {
            GEN_PREDICATE(uint16_t, id);
        } else if (field == "name") {
            GEN_PREDICATE(string, name);
        } else if (field == "color") {
            GEN_PREDICATE(string, color);
        } else if (field == "price") {
            GEN_PREDICATE(double, price);
        } else if (field == "max_speed") {
            GEN_PREDICATE(double, maxSpeed);
        } else if (field == "weight") {
            GEN_PREDICATE(double, weight);
        } else {
            throw std::invalid_argument(field + " is not field of car");
        }
    }
}
