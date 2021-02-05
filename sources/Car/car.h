#pragma once

#include <string>
#include <cstdint>
#include <memory>
#include <functional>


class Car {
public:
    // TODO CarBuilder
    Car(std::string, std::string, double, double, double);

    uint32_t id() const;
    const std::string &name() const;
    const std::string &color() const;
    double price() const;
    double maxSpeed() const;
    double weight() const;

    std::string &name();
    std::string &color();
    double &price();
    double &maxSpeed();
    double &weight();

private:
    const uint32_t _id;
    std::string _name;
    std::string _color;
    double _price;
    double _max_speed;
    double _weight;

private:
    static uint32_t _gID;
};

std::shared_ptr<Car> generateCar();

std::ostream &operator<<(std::ostream &os, const Car &car);

namespace CarFilters {
    std::function<bool(const Car &)> parseCondition(std::istringstream &is);
}
