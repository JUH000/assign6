abstract class Animal {
    abstract fun speak(): String
}

class Dog : Animal() {
    override fun speak(): String {
        return "Woof!"
    }
}

class Cat : Animal() {
    override fun speak(): String {
        return "Meow!"
    }
}

class AnimalFactory {
    fun createAnimal(animalType: String): Animal? {
        return when (animalType.lowercase()) {
            "dog" -> Dog()
            "cat" -> Cat()
            else -> null
        }
    }
}