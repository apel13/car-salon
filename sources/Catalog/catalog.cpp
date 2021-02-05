#include "catalog.h"


#include <memory>
#include <string>


#include <algorithm>

std::vector<Catalog::CarType> Catalog::getCars() const {
    std::vector<Catalog::CarType> ret;
    ret.reserve(_cars.size());
    std::transform(cbegin(_cars), cend(_cars),
                   std::back_inserter(ret),
                   [](decltype(_cars)::value_type const &pair) {
                       return pair.second;
                   });
    return ret;
}


Catalog Catalog::generateCatalog(uint16_t count) {
    Catalog ret;
    auto &cars = ret._cars;

    for (uint16_t i = 0; i < count; ++i) {
        auto carPtr = Car::generateCar();
        cars.insert({carPtr->getID(), carPtr});
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
