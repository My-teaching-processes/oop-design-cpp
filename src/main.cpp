#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "Zoo.h"
#include <iostream>
#include <memory>

/**
 * Основное приложение, демонстрирующее принципы OOP.
 */
int main() {
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "Добро пожаловать в систему управления OOP Zoo!" << std::endl;
    std::cout << std::string(60, '=') << std::endl;

    // Создание зоопарка
    auto zoo = std::make_unique<Zoo>("Парк Sunshine", "Центральный город");
    std::cout << "\nСоздано: " << zoo->toString() << "\n" << std::endl;

    // Создание различных животных
    std::cout << "--- Создание животных ---" << std::endl;
    auto dog = std::make_shared<Dog>("Rex", 5, "Golden Retriever");
    std::cout << dog->getName() << " - " << dog->getSpecies() << std::endl;

    auto cat = std::make_shared<Cat>("Whiskers", 3, "Orange Tabby");
    std::cout << cat->getName() << " - " << cat->getSpecies() << std::endl;

    auto bird1 = std::make_shared<Bird>("Tweety", 2, "Canary");
    std::cout << bird1->getName() << " - " << bird1->getSpecies() << std::endl;

    auto bird2 = std::make_shared<Bird>("Flightless", 10, "Penguin", false);
    std::cout << bird2->getName() << " - " << bird2->getSpecies() << std::endl;

    // Добавление животных в парк
    std::cout << "\n--- Добавление животных в парк ---" << std::endl;
    zoo->addAnimal(dog);
    zoo->addAnimal(cat);
    zoo->addAnimal(bird1);
    zoo->addAnimal(bird2);

    // Отображение всех животных
    zoo->displayAnimals();

    // Животные, издающие звуки
    std::cout << "\n--- Звуки животных ---" << std::endl;
    for (const auto& sound : zoo->getAllSounds()) {
        std::cout << sound << std::endl;
    }

    // Кормление всех животных
    zoo->feedAll();

    // Действия, специфичные для собаки
    std::cout << "\n--- Обучение собаки ---" << std::endl;
    dog->teachTrick("Sit");
    dog->teachTrick("Stay");
    std::cout << dog->performTrick("Sit") << std::endl;
    std::cout << dog->performTrick("Dance") << std::endl;

    // Действия, специфичные для кота
    std::cout << "\n--- Активности кота ---" << std::endl;
    std::cout << cat->scratch("sofa") << std::endl;
    cat->sleep(2);

    // Действия, специфичные для птицы
    std::cout << "\n--- Полет птицы ---" << std::endl;
    std::cout << bird1->fly(100) << std::endl;
    std::cout << bird1->land() << std::endl;
    std::cout << bird2->fly(50) << std::endl;  // Пингвин не может летать

    // Физическая нагрузка для всех животных
    zoo->exerciseAll(20);

    // Отображение обновленной информации
    zoo->displayAnimals();

    // Статистика
    std::cout << "\n--- Статистика парка ---" << std::endl;
    std::cout << "Всего животных: " << zoo->getAnimalCount() << std::endl;
    std::cout << "Собаки: " << zoo->getSpeciesCount("Dog") << std::endl;
    std::cout << "Коты: " << zoo->getSpeciesCount("Cat") << std::endl;
    std::cout << "Птицы: " << zoo->getSpeciesCount("Bird") << std::endl;

    // Поиск конкретного животного
    std::cout << "\n--- Поэск животных ---" << std::endl;
    auto found = zoo->findAnimalByName("Whiskers");
    if (found) {
        std::cout << "Найдено: " << found->getInfo() << std::endl;
    }

    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "Спасибо за посещение парка OOP!" << std::endl;
    std::cout << std::string(60, '=') << std::endl;

    return 0;
}
