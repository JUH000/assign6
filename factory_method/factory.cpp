#include <iostream>
#include <memory>
#include <string>

class Animal {
public:
    virtual std::string speak() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    std::string speak() const override {
        return "Woof!";
    }
};

class Cat : public Animal {
public:
    std::string speak() const override {
        return "Meow!";
    }
};

class AnimalFactory {
public:
    std::unique_ptr<Animal> createAnimal(const std::string& animalType) {
        if (animalType == "dog") {
            return std::make_unique<Dog>();
        } else if (animalType == "cat") {
            return std::make_unique<Cat>();
        }
        return nullptr;
    }
};