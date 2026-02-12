#include "Cat.h"
#include <iostream>
#include <algorithm>

Cat::Cat(const std::string& name, int age, const std::string& color)
    : Animal(name, age, "Cat"), color(color), mood("neutral") {}

std::string Cat::getColor() const {
    return color;
}

std::string Cat::getMood() const {
    return mood;
}

std::string Cat::makeSound() const {
    return name + " says: Meow!";
}

void Cat::eat(const std::string& food) {
    if (energy < 100) {
        energy = std::min(100, energy + 15);
        mood = "happy";
        std::cout << name << " съел " << food << " и теперь очень рад!" << std::endl;
    } else {
        std::cout << name << " сейчас не интересуются в еде." << std::endl;
    }
}

std::string Cat::scratch(const std::string& target) {
    mood = "playful";
    return name + " царапает " + target + "!";
}

std::string Cat::getInfo() const {
    std::string baseInfo = Animal::getInfo();
    return baseInfo + ", Окраска: " + color + ", Унастроение: " + mood;
}
