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

class Program {
    static void Main(string[] args) {
        AnimalFactory factory = new AnimalFactory();

        // Create a Dog and call its Speak method
        Animal dog = factory.CreateAnimal("dog");
        if (dog != null) {
            Console.WriteLine("Dog says: " + dog.Speak());
        } else {
            Console.WriteLine("Failed to create a Dog.");
        }

        // Create a Cat and call its Speak method
        Animal cat = factory.CreateAnimal("cat");
        if (cat != null) {
            Console.WriteLine("Cat says: " + cat.Speak());
        } else {
            Console.WriteLine("Failed to create a Cat.");
        }

        // Try to create an unknown animal
        Animal unknown = factory.CreateAnimal("bird");
        if (unknown != null) {
            Console.WriteLine("Unknown animal says: " + unknown.Speak());
        } else {
            Console.WriteLine("Failed to create an unknown animal.");
        }
    }
}