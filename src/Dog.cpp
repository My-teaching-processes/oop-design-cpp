#include "Dog.h"
#include <iostream>
#include <algorithm>

Dog::Dog(const std::string& name, int age, const std::string& breed)
    : Animal(name, age, "Dog"), breed(breed) {}

std::string Dog::getBreed() const {
    return breed;
}

std::string Dog::makeSound() const {
    return name + " says: Woof! Woof!";
}

void Dog::eat(const std::string& food) {
    if (energy < 100) {
        energy = std::min(100, energy + 20);
        std::cout << name << " съел " << food << " и очень энергичная!" << std::endl;
    } else {
        std::cout << name << " сейчас не голодна." << std::endl;
    }
}

void Dog::teachTrick(const std::string& trick) {
    if (std::find(tricks.begin(), tricks.end(), trick) == tricks.end()) {
        tricks.push_back(trick);
        std::cout << name << " научилась новому трюку: " << trick << "!" << std::endl;
    }
}

std::string Dog::performTrick(const std::string& trick) {
    if (energy < 10) {
        return name + " слишком устала для выконения трюков.";
    } else if (std::find(tricks.begin(), tricks.end(), trick) != tricks.end()) {
        energy -= 10;
        return name + " performed the trick: " + trick + "!";
    } else {
        return name + " hasn't learned the " + trick + " trick yet.";
    }
}

std::string Dog::getInfo() const {
    std::string baseInfo = Animal::getInfo();
    std::string tricksInfo = ", Трюки: ";
    
    if (tricks.empty()) {
        tricksInfo += "Нет";
    } else {
        for (size_t i = 0; i < tricks.size(); ++i) {
            if (i > 0) tricksInfo += ", ";
            tricksInfo += tricks[i];
        }
    }
    
    return baseInfo + tricksInfo + ", Порода: " + breed;
}
