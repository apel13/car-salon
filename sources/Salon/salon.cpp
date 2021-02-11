#include "salon.h"

#include <iostream>
#include <iomanip>


using namespace std;

Salon::Salon()
        : _catalog(generateCatalog()), _filtered(_catalog) {}

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
        _filtered.extract(id);
        return true;
    }
    return false;
}


