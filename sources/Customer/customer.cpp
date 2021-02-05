#include "customer.h"

Customer::Customer(const std::string &name)
        : _name(name), _car(nullptr) {}

const std::string &Customer::getName() const {
    return _name;
}

std::shared_ptr<const Car> Customer::getCar() const {
    return _car;
}

void Customer::setCar(const std::shared_ptr<const Car> &car) {
    _car = car;
}
