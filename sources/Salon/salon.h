#pragma once

#include "catalog.h"
#include "customer.h"

#include <fstream>

class Salon {
public:
    Salon();

    void showCarList() const;
    void showFilteredCarList() const;
    void filter(const Catalog::PredicateType &pred);
    void resetFilters();
    bool buy(Customer &customer, uint16_t id);

private:
    Catalog _catalog;
    Catalog _filtered;
};




