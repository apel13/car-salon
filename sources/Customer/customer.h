#pragma once

#include "Car/car.h"

class Customer {
public:
    Customer(const std::string &name)
            : _name(name), _car(nullptr)
    {}

    const std::string &getName() const {
        return _name;
    }

    std::shared_ptr<const Car> getCar() const {
        return _car;
    }

    void setCar(const std::shared_ptr<const Car> &car) {
        _car = car;
    }

private:
    const std::string _name;
    std::shared_ptr<const Car> _car;
};

