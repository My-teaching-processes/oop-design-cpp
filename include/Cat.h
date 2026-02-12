#pragma once

#include "Animal.h"

/**
 * Класс кота, демонстрирующий другую конкретную реализацию Animal.
 */
class Cat : public Animal {
public:
    /**
     * Инициализация кота.
     * 
     * @param name Имя кота
     * @param age Возраст кота
     * @param color Окраска/пыстерн кота
     */
    Cat(const std::string& name, int age, const std::string& color);

    /**
     * Получить окраску кота.
     */
    std::string getColor() const;

    /**
     * Получить унастроение кота.
     */
    std::string getMood() const;

    /**
     * Вернуть звук, который издает кот.
     */
    std::string makeSound() const override;

    /**
     * Накормить кота.
     */
    void eat(const std::string& food) override;

    /**
     * Кот царапает что-нибудь.
     * 
     * @param target Объект, который царапает кот
     * @return Описание акции царапания
     */
    std::string scratch(const std::string& target = "furniture");

    /**
     * Получить подробную информацию о коте.
     */
    std::string getInfo() const override;

private:
    std::string color;
    std::string mood;
};
