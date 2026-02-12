#pragma once

#include "Animal.h"
#include <vector>

/**
 * Класс собаки, демонстрирующий конкретную реализацию базового класса Animal.
 * 
 * Этот класс демонстрирует:
 * - Наследование от абстрактного базового класса
 * - Реализацию абстрактных методов
 * - Полиморфизм
 */
class Dog : public Animal {
public:
    /**
     * Инициализация собаки.
     * 
     * @param name Имя собаки
     * @param age Возраст собаки
     * @param breed Порода собаки
     */
    Dog(const std::string& name, int age, const std::string& breed);

    /**
     * Получить породу собаки.
     */
    std::string getBreed() const;

    /**
     * Вернуть звук, который издает собака.
     */
    std::string makeSound() const override;

    /**
     * Накормить собаку.
     */
    void eat(const std::string& food) override;

    /**
     * Научить собаку новому трюку.
     * 
     * @param trick Название трюка
     */
    void teachTrick(const std::string& trick);

    /**
     * Выполнить изученный трюк.
     * 
     * @param trick Трюк для выполнения
     * @return Описание выполнения трюка
     */
    std::string performTrick(const std::string& trick);

    /**
     * Получить подробную информацию о собаке.
     */
    std::string getInfo() const override;

private:
    std::string breed;
    std::vector<std::string> tricks;
};
