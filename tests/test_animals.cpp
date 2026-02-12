#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "Zoo.h"
#include <memory>

// Тесты для класса Dog
class DogTest : public ::testing::Test {
protected:
    std::shared_ptr<Dog> dog;
    
    void SetUp() override {
        dog = std::make_shared<Dog>("Max", 3, "Labrador");
    }
};

TEST_F(DogTest, Initialization) {
    EXPECT_EQ(dog->getName(), "Max");
    EXPECT_EQ(dog->getAge(), 3);
    EXPECT_EQ(dog->getBreed(), "Labrador");
}

TEST_F(DogTest, Sound) {
    std::string sound = dog->makeSound();
    EXPECT_THAT(sound, ::testing::HasSubstr("Woof"));
}

TEST_F(DogTest, TeachTrick) {
    dog->teachTrick("Fetch");
    std::string result = dog->performTrick("Fetch");
    EXPECT_THAT(result, ::testing::HasSubstr("performed"));
}

// Тесты для класса Cat
class CatTest : public ::testing::Test {
protected:
    std::shared_ptr<Cat> cat;
    
    void SetUp() override {
        cat = std::make_shared<Cat>("Luna", 2, "Gray");
    }
};

TEST_F(CatTest, Sound) {
    std::string sound = cat->makeSound();
    EXPECT_THAT(sound, ::testing::HasSubstr("Meow"));
}

TEST_F(CatTest, Eat) {
    cat->exercise(20);  // Уменьшить энергию
    int initialEnergy = cat->getEnergy();
    cat->eat("fish");
    EXPECT_GT(cat->getEnergy(), initialEnergy);
}

// Тесты для класса Bird
class BirdTest : public ::testing::Test {
protected:
    std::shared_ptr<Bird> bird;
    
    void SetUp() override {
        bird = std::make_shared<Bird>("Polly", 1, "Parrot");
    }
};

TEST_F(BirdTest, Fly) {
    std::string result = bird->fly(50);
    EXPECT_THAT(result, ::testing::HasSubstr("flew"));
    EXPECT_EQ(bird->getAltitude(), 50);
}

TEST_F(BirdTest, CannotFly) {
    auto penguin = std::make_shared<Bird>("Pingu", 5, "Penguin", false);
    std::string result = penguin->fly(100);
    EXPECT_THAT(result, ::testing::HasSubstr("cannot fly"));
}

TEST_F(BirdTest, Sleep) {
    bird->exercise(30);  // Уменьшить энергию
    bird->sleep(2);      // Восстановить энергию
    EXPECT_GT(bird->getEnergy(), 40);
}

// Тесты для класса Zoo
class ZooTest : public ::testing::Test {
protected:
    std::shared_ptr<Zoo> zoo;
    std::shared_ptr<Dog> dog;
    std::shared_ptr<Cat> cat;
    
    void SetUp() override {
        zoo = std::make_shared<Zoo>("Test Zoo", "TestCity");
        dog = std::make_shared<Dog>("Buddy", 4, "Beagle");
        cat = std::make_shared<Cat>("Mittens", 1, "White");
    }
};

TEST_F(ZooTest, Initialization) {
    EXPECT_EQ(zoo->getName(), "Test Zoo");
    EXPECT_EQ(zoo->getLocation(), "TestCity");
    EXPECT_EQ(zoo->getAnimalCount(), 0);
}

TEST_F(ZooTest, AddAnimal) {
    zoo->addAnimal(dog);
    EXPECT_EQ(zoo->getAnimalCount(), 1);
}

TEST_F(ZooTest, RemoveAnimal) {
    zoo->addAnimal(dog);
    bool result = zoo->removeAnimal(dog);
    EXPECT_TRUE(result);
    EXPECT_EQ(zoo->getAnimalCount(), 0);
}

TEST_F(ZooTest, FindAnimalByName) {
    zoo->addAnimal(dog);
    auto found = zoo->findAnimalByName("Buddy");
    EXPECT_EQ(found, dog);
}

TEST_F(ZooTest, SpeciesCount) {
    zoo->addAnimal(dog);
    zoo->addAnimal(cat);
    EXPECT_EQ(zoo->getSpeciesCount("Dog"), 1);
    EXPECT_EQ(zoo->getSpeciesCount("Cat"), 1);
}

TEST_F(ZooTest, GetAllSounds) {
    zoo->addAnimal(dog);
    zoo->addAnimal(cat);
    auto sounds = zoo->getAllSounds();
    EXPECT_EQ(sounds.size(), 2);
}

TEST_F(ZooTest, AnimalsProperty) {
    zoo->addAnimal(dog);
    const auto& animals = zoo->getAnimals();
    EXPECT_EQ(animals.size(), 1);
}
