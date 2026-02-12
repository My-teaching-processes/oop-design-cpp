# Руководство разработчика - OOP Design C++

## Введение

Этот документ содержит подробное руководство для разработчиков, работающих с C++ версией проекта OOP Design.

## Архитектура проекта

### Иерархия классов

```
Animal (абстрактный)
├── Dog
├── Cat
└── Bird

Zoo
├── содержит: std::vector<std::shared_ptr<Animal>>
```

### Ключевые компоненты

#### 1. Animal.h / Animal.cpp
- **Назначение**: Абстрактный базовый класс для всех животных
- **Ответственность**: Инкапсуляция общих свойств и поведения
- **Методы**:
  - `makeSound()` - чистая виртуальная функция
  - `eat()` - чистая виртуальная функция
  - `sleep()` - конкретная реализация
  - `exercise()` - конкретная реализация
  - `getInfo()` - виртуальная функция

#### 2. Dog.h / Dog.cpp
- **Назначение**: Конкретная реализация животного - собака
- **Дополнительные свойства**: порода, трюки
- **Дополнительные методы**:
  - `teachTrick()` - обучить новому трюку
  - `performTrick()` - выполнить трюк

#### 3. Cat.h / Cat.cpp
- **Назначение**: Конкретная реализация животного - кот
- **Дополнительные свойства**: цвет, настроение
- **Дополнительные методы**:
  - `scratch()` - царапать предметы

#### 4. Bird.h / Bird.cpp
- **Назначение**: Конкретная реализация животного - птица
- **Дополнительные свойства**: может ли летать, высота
- **Дополнительные методы**:
  - `fly()` - летать на определенную высоту
  - `land()` - приземлиться

#### 5. Zoo.h / Zoo.cpp
- **Назначение**: Управление коллекцией животных
- **Ответственность**: Добавление, удаление, поиск животных
- **Использует**: `std::vector<std::shared_ptr<Animal>>`

## Память и управление ресурсами

### Умные указатели

```cpp
// Для единственного владельца ресурса
std::unique_ptr<Zoo> zoo = std::make_unique<Zoo>("Name", "Location");

// Для общего владения ресурсом
std::shared_ptr<Animal> dog = std::make_shared<Dog>("Rex", 5, "Labrador");

// Автоматическое управление памятью - деструкторы вызываются автоматически
```

### Почему не используются raw-указатели?

- ✅ Автоматическое управление памятью
- ✅ Предотвращение утечек памяти
- ✅ Исключение ошибок с double-delete
- ✅ Более безопасный и читаемый код

## Полиморфизм и виртуальные функции

### Чистые виртуальные функции

```cpp
// В базовом классе
virtual std::string makeSound() const = 0;

// В производном классе
std::string makeSound() const override;
```

### Ключевые моменты

- `= 0` означает "чистая виртуальная функция" (абстрактная)
- `override` - явное указание на переопределение (рекомендуется)
- Виртуальный деструктор обязателен для базовых классов:
  ```cpp
  virtual ~Animal() = default;
  ```

## Контейнеры STL

### Использование std::vector

```cpp
std::vector<std::shared_ptr<Animal>> animals;

// Добавление
animals.push_back(dog);

// Поиск
auto it = std::find(animals.begin(), animals.end(), dog);

// Удаление
animals.erase(it);

// Итерация
for (auto& animal : animals) {
    animal->eat("food");
}
```

## Тестирование с Google Test

### Структура теста

```cpp
class DogTest : public ::testing::Test {
protected:
    std::shared_ptr<Dog> dog;
    
    void SetUp() override {
        dog = std::make_shared<Dog>("Max", 3, "Labrador");
    }
};

TEST_F(DogTest, TestName) {
    EXPECT_EQ(dog->getName(), "Max");
}
```

### Часто используемые утверждения

```cpp
EXPECT_EQ(a, b);              // a == b
EXPECT_NE(a, b);              // a != b
EXPECT_TRUE(condition);        // условие истинно
EXPECT_FALSE(condition);       // условие ложно
EXPECT_THAT(str, HasSubstr("text"));  // строка содержит текст
EXPECT_GT(a, b);              // a > b
EXPECT_LT(a, b);              // a < b
```

## Сборка проекта

### CMake команды

```bash
# Кonfiguration
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build . --config Release

# Testing
ctest --verbose
```

### Несколько вариантов генераторов

```bash
# Unix/Linux
cmake .. -G "Unix Makefiles"

# Visual Studio
cmake .. -G "Visual Studio 16 2019"

# Ninja
cmake .. -G Ninja
```

## Добавление нового животного

### Шаг 1: Создать заголовок

```cpp
// include/Elephant.h
#pragma once
#include "Animal.h"

class Elephant : public Animal {
public:
    Elephant(const std::string& name, int age);
    std::string makeSound() const override;
    void eat(const std::string& food) override;
};
```

### Шаг 2: Реализовать класс

```cpp
// src/Elephant.cpp
#include "Elephant.h"

Elephant::Elephant(const std::string& name, int age)
    : Animal(name, age, "Elephant") {}

std::string Elephant::makeSound() const {
    return name + " says: Trumpet!";
}

void Elephant::eat(const std::string& food) {
    energy = std::min(100, energy + 30);
    // ... реализация
}
```

### Шаг 3: Обновить CMakeLists.txt

```cmake
set(SOURCES
    src/Animal.cpp
    src/Dog.cpp
    src/Cat.cpp
    src/Bird.cpp
    src/Elephant.cpp  # Добавить это
    src/Zoo.cpp
)
```

### Шаг 4: Добавить тесты

```cpp
class ElephantTest : public ::testing::Test {
protected:
    std::shared_ptr<Elephant> elephant;
    
    void SetUp() override {
        elephant = std::make_shared<Elephant>("Dumbo", 10);
    }
};

TEST_F(ElephantTest, Sound) {
    EXPECT_THAT(elephant->makeSound(), 
                ::testing::HasSubstr("Trumpet"));
}
```

## Отладка

### Использование GDB

```bash
# Компиляция с символами отладки
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

# Запуск отладчика
gdb ./zoo_app

# Команды GDB
(gdb) break main
(gdb) run
(gdb) step
(gdb) next
(gdb) print variable
(gdb) continue
(gdb) quit
```

## Производительность

### Что избегать

```cpp
// ❌ Неэффективно - копирование
std::vector<Animal> animals;
animals.push_back(dog);

// ✅ Эффективно - использование указателей
std::vector<std::shared_ptr<Animal>> animals;
animals.push_back(dog);
```

### Оптимизация

```cpp
// ❌ Копирует данные
std::string getName() { return name; }

// ✅ Возвращает ссылку
const std::string& getName() const { return name; }
```

## Рекомендации по кодированию

1. **Используйте const везде, где это возможно**
   ```cpp
   const std::string& getName() const;
   ```

2. **Предпочитайте новые стили **
   ```cpp
   auto result = std::make_shared<Dog>("Rex", 5, "Labrador");
   ```

3. **Используйте range-based loops**
   ```cpp
   for (const auto& animal : zoo->getAnimals()) {
       std::cout << animal->getInfo() << std::endl;
   }
   ```

4. **Избегайте глобальных переменных**
   - Передавайте зависимости как параметры

5. **Документируйте код комментариями Doxygen**
   ```cpp
   /// Краткое описание
   /// 
   /// @param name Описание параметра
   /// @return Описание возвращаемого значения
   ```

## Ссылки и ресурсы

- [cppreference.com](https://en.cppreference.com/) - Справочника по C++
- [Google Test]( https://github.com/google/googletest) - Фреймворк для тестирования
- [Modern C++](https://isocpp.org/) - Официальный стандарт C++
- [CMake Documentation](https://cmake.org/documentation/) - CMake документация

## Часто задаваемые вопросы

**Q: Почему использовать std::shared_ptr вместо std::unique_ptr?**
A: Потому что Zoo должен управлять только содержимым животных.

**Q: Когда следует использовать virtual?**
A: Когда производные классы должны иметь возможность переопределять поведение.

**Q: Как избежать утечек памяти?**
A: Используйте умные указатели и избегайте raw-указателей.

**Q: Что такое override?**
A: Это ключевое слово для явного указания переопределения виртуальной функции. Помогает обнаружить ошибки.
