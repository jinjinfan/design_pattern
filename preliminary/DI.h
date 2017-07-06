//
// Created by claudia on 2017/7/5.
//

#ifndef SPECIFICATION_DI_H
#define SPECIFICATION_DI_H

#include <iostream>
#include <string>
#include <memory>
#include "di.hpp"

struct ILogger {
    virtual void log(const std::string& s) = 0;
};

struct Logger : ILogger{
    void log(const std::string &s) override {
        std::cout << "Log: " << s << std::endl;
    }
};

struct Engine {
    float volume = 5;
    int horse_power = 100;

    friend std::ostream &operator<<(std::ostream &os, const Engine &engine) {
        os << "volume: " << engine.volume << " horse_power: " << engine.horse_power;
        return os;
    }
};

struct Car {
    std::shared_ptr<Engine> engine;
    std::shared_ptr<ILogger> logger;

    Car(const std::shared_ptr<Engine> &engine, const std::shared_ptr<ILogger> &logger) : engine(engine),
                                                                                         logger(logger) {
        logger->log("Car was build");
    }

    friend std::ostream &operator<<(std::ostream &os, const Car &car) {
        os << " car with engine: " << *car.engine;
        return os;
    }
};

#endif //SPECIFICATION_DI_H
