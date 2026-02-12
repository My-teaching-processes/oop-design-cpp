#include "Animal.h"
#include <iostream>
#include <algorithm>

Animal::Animal(const std::string& name, int age, const std::string& species)
    : name(name), age(age), species(species), energy(100) {}

std::string Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

std::string Animal::getSpecies() const {
    return species;
}

int Animal::getEnergy() const {
    return energy;
}

void Animal::sleep(int hours) {
    int energyGain = std::min(hours * 10, 100 - energy);
    energy += energyGain;
    std::cout << name << " спал " << hours << " час(ов) и получил " 
              << energyGain << " энергии." << std::endl;
}

void Animal::exercise(int minutes) {
    int energyLoss = std::min(minutes / 5, energy);
    energy -= energyLoss;
    std::cout << name << " занимался " << minutes << " минут и потерял " 
              << energyLoss << " энергии." << std::endl;
}

std::string Animal::getInfo() const {
    return "Имя: " + name + ", Вид: " + species + 
           ", Возраст: " + std::to_string(age) + " лет, Энергия: " + 
           std::to_string(energy) + "/100";
}
