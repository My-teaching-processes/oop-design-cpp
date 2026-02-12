#pragma once

#include "Animal.h"
#include <memory>
#include <vector>

/**
 * Класс Zoo, демонстрирующий композицию и управление коллекцией.
 * 
 * Этот класс демонстрирует:
 * - Композицию (отношение "имеет")
 * - Управление коллекцией
 * - Принцип единственной ответственности
 */
class Zoo {
public:
    /**
     * Инициализация зоопарка.
     * 
     * @param name Название зоопарка
     * @param location Локация зоопарка
     */
    Zoo(const std::string& name, const std::string& location);

    /**
     * Получить название зоопарка.
     */
    std::string getName() const;

    /**
     * Получить локацию зоопарка.
     */
    std::string getLocation() const;

    /**
     * Получить всех животных в зоопарке.
     */
    const std::vector<std::shared_ptr<Animal>>& getAnimals() const;

    /**
     * Добавить животное в зоопарк.
     * 
     * @param animal Животное для добавления
     */
    void addAnimal(std::shared_ptr<Animal> animal);

    /**
     * Удалить животное из зоопарка.
     * 
     * @param animal Животное для удаления
     * @return True если животное было удалено, False если не найдено
     */
    bool removeAnimal(std::shared_ptr<Animal> animal);

    /**
     * Найти животное по основаню имени.
     * 
     * @param name Наименование для поиска
     * @return Животное если найдено, nullptr иначе
     */
    std::shared_ptr<Animal> findAnimalByName(const std::string& name);

    /**
     * Получить звуки со всех животных.
     * 
     * @return Вектор звуков сделан всеми животными
     */
    std::vector<std::string> getAllSounds() const;

    /**
     * Накормить всех животных в зоопарке.
     */
    void feedAll();

    /**
     * Физическая нагрузка для всех животных.
     * 
     * @param minutes Время физической нагружу (минут)
     */
    void exerciseAll(int minutes);

    /**
     * Получить количество животных в зоопарке.
     */
    size_t getAnimalCount() const;

    /**
     * Посетимость животных определенного вида.
     * 
     * @param species Вид для наслчета
     * @return Количество животных этот вид
     */
    size_t getSpeciesCount(const std::string& species) const;

    /**
     * Отобразить информацию о всех животных в зоопарке.
     */
    void displayAnimals() const;

    /**
     * Получить строковое представление зоопарка.
     */
    std::string toString() const;

private:
    std::string name;
    std::string location;
    std::vector<std::shared_ptr<Animal>> animals;
};
