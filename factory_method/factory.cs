using System;

abstract class Animal {
    public abstract string Speak();
}

class Dog : Animal {
    public override string Speak() {
        return "Woof!";
    }
}

class Cat : Animal {
    public override string Speak() {
        return "Meow!";
    }
}

class AnimalFactory {
    public Animal CreateAnimal(string animalType) {
        if (animalType == "dog") {
            return new Dog();
        } else if (animalType == "cat") {
            return new Cat();
        }
        return null;
    }
}