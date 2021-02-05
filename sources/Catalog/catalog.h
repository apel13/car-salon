#pragma once



#include <unordered_map>
#include <functional>
#include <vector>
#include <fstream>

#include "Car/car.h"


class Catalog {
public:
    using CarType       = std::shared_ptr<const Car>;
    using ContainerType = std::unordered_map<uint16_t, CarType>;
    using PredicateType = std::function<bool(const Car &)>;

    std::vector<CarType> getCars() const;
    CarType extract(uint16_t id);
    Catalog filter(const PredicateType &pred);

    static Catalog generateCatalog(uint16_t count = 10);
private:
    ContainerType _cars;
};

std::ostream &operator<<(std::ostream &os, const Catalog &catalog);
