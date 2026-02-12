#pragma once

#include "Animal.h"

/**
 * Класс птицы, демонстрирующий еще одну конкретную реализацию Animal.
 */
class Bird : public Animal {
public:
    /**
     * Инициализация птицы.
     * 
     * @param name Имя птицы
     * @param age Возраст птицы
     * @param species Вид птицы
     * @param canFly Может ли птица летать
     */
    Bird(const std::string& name, int age, const std::string& species, bool canFly = true);

    /**
     * Проверить, может ли птица летать.
     */
    bool getCanFly() const;

    /**
     * Получить текущую высоту птицы.
     */
    int getAltitude() const;

    /**
     * Вернуть звук, который издает птица.
     */
    std::string makeSound() const override;

    /**
     * Накормить птицу.
     */
    void eat(const std::string& food) override;

    /**
     * Дать птице летать на определенной высоте.
     * 
     * @param altitude Целевая высота в метрах
     * @return Описание полета или сообщение об ошибке
     */
    std::string fly(int altitude);

    /**
     * На землю птице.
     */
    std::string land();

    /**
     * Получить подробную информацию о птице.
     */
    std::string getInfo() const override;

private:
    bool canFly;
    int altitude;
};
