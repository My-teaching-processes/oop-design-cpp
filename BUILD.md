# Запуск проекта на C++

## Требования
- C++17 или более поздняя версия
- CMake 3.10+
- Компилятор GCC, Clang или MSVC

## Сборка и тестирование

### Quick Start (Linux/Mac)
```bash
cd oop-design-cpp
mkdir build && cd build
cmake ..
make
./zoo_app          # Запустить основное приложение
./tests            # Запустить тесты
```

### Quick Start (Windows - MSVC)
```cmd
cd oop-design-cpp
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
zoo_app.exe        # Запустить основное приложение
tests.exe          # Запустить тесты
```

### Quick Start (Windows - MinGW)
```cmd
cd oop-design-cpp
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
zoo_app.exe
tests.exe
```

## Структура файлов

- `include/` - Заголовочные файлы (.h)
- `src/` - Файлы реализации (.cpp)
- `tests/` - Модульные тесты
- `build/` - Итоговые файлы сборки

## Компиляция отдельных компонентов

```bash
# Только основное приложение
cmake --build . --target zoo_app

# Только тесты
cmake --build . --target tests

# Полная сборка
cmake --build .
```

## Отладка

Для отладки скомпилируйте с флагами отладки:
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
gdb ./zoo_app  # Linux/Mac
```
