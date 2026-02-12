#pragma once

#include <string>

/**
 * Абстрактный базовый класс для всех животных.
 * 
 * Этот класс демонстрирует:
 * - Инкапсуляцию (приватные атрибуты с методами доступа)
 * - Наследование (базовый класс для подклассов)
 * - Абстракцию (чистые виртуальные методы)
 */
class Animal {
public:
    /**
     * Инициализация животного.
     * 
     * @param name Имя животного
     * @param age Возраст животного в годах
     * @param species Вид животного
     */
    Animal(const std::string& name, int age, const std::string& species);

    /**
     * Виртуальный деструктор для правильной очистки памяти.
     */
    virtual ~Animal() = default;

    /**
     * Получить имя животного.
     */
    std::string getName() const;

    /**
     * Получить возраст животного.
     */
    int getAge() const;

    /**
     * Получить вид животного.
     */
    std::string getSpecies() const;

    /**
     * Получить уровень энергии животного.
     */
    int getEnergy() const;

    /**
     * Вернуть звук, который издает животное.
     * Это чистый виртуальный метод, который должен быть реализован подклассами.
     */
    virtual std::string makeSound() const = 0;

    /**
     * Накормить животное.
     */
    virtual void eat(const std::string& food) = 0;

    /**
     * Уложить животное спать.
     * 
     * @param hours Количество часов сна
     */
    void sleep(int hours);

    /**
     * Физическая нагрузка для животного.
     * 
     * @param minutes Продолжительность упражнения в минутах
     */
    void exercise(int minutes);

    /**
     * Получить подробную информацию о животном.
     */
    virtual std::string getInfo() const;

protected:
    std::string name;
    int age;
    std::string species;
    int energy;
};
