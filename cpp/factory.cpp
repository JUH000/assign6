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

int main() {
    AnimalFactory factory;

    // Create a Dog and call its speak method
    auto dog = factory.createAnimal("dog");
    if (dog) {
        std::cout << "Dog says: " << dog->speak() << std::endl;
    } else {
        std::cout << "Failed to create a Dog." << std::endl;
    }

    // Create a Cat and call its speak method
    auto cat = factory.createAnimal("cat");
    if (cat) {
        std::cout << "Cat says: " << cat->speak() << std::endl;
    } else {
        std::cout << "Failed to create a Cat." << std::endl;
    }

    // Try to create an unknown animal
    auto unknown = factory.createAnimal("bird");
    if (unknown) {
        std::cout << "Unknown animal says: " << unknown->speak() << std::endl;
    } else {
        std::cout << "Failed to create an unknown animal." << std::endl;
    }

    return 0;
}