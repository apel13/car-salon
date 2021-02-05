#pragma once


#include <unordered_map>
#include <functional>
#include <vector>
#include <fstream>

#include "car.h"


class Catalog {
public:
    using CarType = std::shared_ptr<const Car>;
    using PredicateType = std::function<bool(const Car &)>;

    std::vector<CarType>    getCars() const;
    CarType                 extract(uint16_t id);
    Catalog                 filter(const PredicateType &pred);

    friend Catalog          generateCatalog(uint16_t count);

private:
    std::unordered_map<uint16_t, CarType> _cars;
};

Catalog generateCatalog(uint16_t count = 10);

std::ostream &operator<<(std::ostream &os, const Catalog &catalog);
