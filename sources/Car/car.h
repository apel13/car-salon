#pragma once

#include <string>
#include <cstdint>
#include <memory>



class Car {
public:
    Car(std::string, std::string, double, double, double);

    // getters
    uint32_t getID()                const;
    const std::string &getName()    const;
    const std::string &getColor()   const;
    double getPrice()               const;
    double getMaxSpeed()            const;
    double getWeight()              const;

    // setters
    void setName(const std::string &name);
    void setColor(const std::string &color);
    void setMaxSpeed(double maxSpeed);
    void setWeight(double weight);

private:
    const uint32_t  _id;
    std::string     _name;
    std::string     _color;
    double          _price;
    double          _max_speed;
    double          _weight;

// static members
public:
    static std::shared_ptr<Car> generateCar();
private:
    static uint32_t _gID;
};

std::ostream &operator<<(std::ostream &os, const Car &car);
