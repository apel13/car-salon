#include "catalog.h"

#include <string>


#include <algorithm>
#include <iomanip>

using namespace std;


vector<Catalog::CarType> Catalog::getCars() const {
    vector<Catalog::CarType> ret;
    ret.reserve(_cars.size());
    transform(cbegin(_cars), cend(_cars),
              back_inserter(ret),
              [](decltype(_cars)::value_type const &pair) {
                  return pair.second;
              });
    return ret;
}


Catalog generateCatalog(uint16_t count) {
    Catalog ret;
    for (uint16_t i = 0; i < count; ++i) {
        auto carPtr = generateCar();
        ret._cars.insert({carPtr->id(), carPtr});
    }
    return ret;
}

Catalog::CarType Catalog::extract(uint16_t id) {
    auto it = _cars.find(id);
    if (it == _cars.end())
        return nullptr;
    return _cars.extract(it).mapped();
}


Catalog Catalog::filter(const Catalog::PredicateType &pred) {
    Catalog ret = *this;
    auto &cars = ret._cars;
    for (auto it = cars.begin(); it != cars.end();) {
        if (!pred(*it->second))
            it = cars.erase(it);
        else ++it;
    }
    return ret;
}

ostream &operator<<(ostream &os, const Catalog &catalog) {
    os
            << setw(6) << left << "id"
            << setw(8) << left << "name"
            << setw(10) << left << "color"
            << setw(11) << left << "price"
            << setw(10) << left << "max_speed"
            << setw(7) << left << "weight"
            << endl;
    for (const auto &car : catalog.getCars())
        os << *car << endl;
    return os;
}

