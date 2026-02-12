#include "Bird.h"
#include <iostream>
#include <algorithm>

Bird::Bird(const std::string& name, int age, const std::string& species, bool canFly)
    : Animal(name, age, species), canFly(canFly), altitude(0) {}

bool Bird::getCanFly() const {
    return canFly;
}

int Bird::getAltitude() const {
    return altitude;
}

std::string Bird::makeSound() const {
    return name + " says: Tweet! Tweet!";
}

void Bird::eat(const std::string& food) {
    if (energy < 100) {
        energy = std::min(100, energy + 10);
        std::cout << name << " съел " << food << " и чувствует себя энергичным!" << std::endl;
    } else {
        std::cout << name << " имеет достаточно энергии." << std::endl;
    }
}

std::string Bird::fly(int alt) {
    if (!canFly) {
        return name + " cannot fly.";
    } else if (energy < 20) {
        return name + " is too tired to fly.";
    } else {
        altitude = alt;
        energy -= 20;
        return name + " flew to " + std::to_string(altitude) + " meters altitude!";
    }
}

std::string Bird::land() {
    altitude = 0;
    return name + " has landed!";
}

std::string Bird::getInfo() const {
    std::string baseInfo = Animal::getInfo();
    std::string flyStatus = canFly ? "Да" : "Нет";
    return baseInfo + ", Может летать: " + flyStatus + ", Высота: " + 
           std::to_string(altitude) + "м";
}
