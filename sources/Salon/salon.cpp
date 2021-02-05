#include "salon.h"

#include <iostream>
#include <iomanip>


using namespace std;

Salon::Salon()
        : _catalog(Catalog::generateCatalog()), _filtered(_catalog) {}

void Salon::showCarList() const {
    cout << _catalog << endl;
}

void Salon::showFilteredCarList() const {
    cout << _filtered << endl;
}

void Salon::filter(const Catalog::PredicateType &pred) {
    _filtered = _filtered.filter(pred);
}

void Salon::resetFilters() {
    _filtered = _catalog;
}

bool Salon::buy(Customer &customer, uint16_t id) {
    auto ptr = _catalog.extract(id);
    if (ptr) {
        // if we need to revert previous car
        // to the _catalog, it should be done here
        customer.setCar(ptr);
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, const Catalog &catalog) {
    os
            << setw(4) << left << "id"
            << setw(7) << left << "name"
            << setw(9) << left << "color"
            << setw(9) << left << "price"
            << setw(6) << left << "max_speed"
            << setw(7) << left << "weight"
            << endl;
    for (const auto &car : catalog.getCars())
        os << *car << endl;
    return os;
}
