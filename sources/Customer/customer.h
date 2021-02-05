#pragma once

#include "car.h"

class Customer {
public:
    Customer(const std::string &name);

    const std::string &getName() const;
    std::shared_ptr<const Car> getCar() const;
    void setCar(const std::shared_ptr<const Car> &car);

private:
    const std::string _name;
    std::shared_ptr<const Car> _car;
};

