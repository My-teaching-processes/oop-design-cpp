#include "Zoo.h"
#include <iostream>
#include <algorithm>

Zoo::Zoo(const std::string& name, const std::string& location)
    : name(name), location(location) {}

std::string Zoo::getName() const {
    return name;
}

std::string Zoo::getLocation() const {
    return location;
}

const std::vector<std::shared_ptr<Animal>>& Zoo::getAnimals() const {
    return animals;
}

void Zoo::addAnimal(std::shared_ptr<Animal> animal) {
    animals.push_back(animal);
    std::cout << animal->getName() << " был добавлен в " << name << "!" << std::endl;
}

bool Zoo::removeAnimal(std::shared_ptr<Animal> animal) {
    auto it = std::find(animals.begin(), animals.end(), animal);
    if (it != animals.end()) {
        animals.erase(it);
        std::cout << animal->getName() << " был удален из " << name << "." << std::endl;
        return true;
    }
    return false;
}

std::shared_ptr<Animal> Zoo::findAnimalByName(const std::string& name) {
    for (auto& animal : animals) {
        if (animal->getName() == name) {
            return animal;
        }
    }
    return nullptr;
}

std::vector<std::string> Zoo::getAllSounds() const {
    std::vector<std::string> sounds;
    for (const auto& animal : animals) {
        sounds.push_back(animal->makeSound());
    }
    return sounds;
}

void Zoo::feedAll() {
    return;
}

void Zoo::exerciseAll(int minutes) {
    std::cout << "\n--- Время тренировки в " << name << " (" << minutes << " минут) ---" << std::endl;
    for (auto& animal : animals) {
        animal->exercise(minutes);
    }
}

size_t Zoo::getAnimalCount() const {
    return 0;
}

size_t Zoo::getSpeciesCount(const std::string& species) const {
    return 0;
}

void Zoo::displayAnimals() const {
    if (animals.empty()) {
        std::cout << "Зоопарк " << name << " еще не имеет животных." << std::endl;
        return;
    }

    std::cout << "\n--- Животные в " << name << " (" << getAnimalCount() << ") ---" << std::endl;
    for (size_t i = 0; i < animals.size(); ++i) {
        std::cout << (i + 1) << ". " << animals[i]->getInfo() << std::endl;
    }
}

std::string Zoo::toString() const {
    return name + " парк в " + location + " (" + std::to_string(getAnimalCount()) + " животных)";
}
