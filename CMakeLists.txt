cmake_minimum_required(VERSION 3.10)
project(OOPDesignCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавить директорию include
include_directories(${PROJECT_SOURCE_DIR}/include)

# Исходные файлы для основного приложения
set(SOURCES
    src/Animal.cpp
    src/Dog.cpp
    src/Cat.cpp
    src/Bird.cpp
    src/Zoo.cpp
)

# Создать экземпляр библиотеки
add_library(oop_lib ${SOURCES})

# Создать основное приложение
add_executable(zoo_app src/main.cpp)
target_link_libraries(zoo_app PRIVATE oop_lib)

# Включить Google Test
enable_testing()

# Загрузить Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

FetchContent_MakeAvailable(googletest)

# Создать тестовый исполняемый файл
add_executable(tests tests/test_animals.cpp)
target_link_libraries(tests PRIVATE oop_lib gtest gtest_main)

add_test(NAME UnitTests COMMAND tests)
