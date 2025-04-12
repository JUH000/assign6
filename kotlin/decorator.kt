open class Coffee {
    open fun cost(): Int {
        return 5
    }
}

open class CoffeeDecorator(private val coffee: Coffee) : Coffee() {
    override fun cost(): Int {
        return coffee.cost()
    }
}

class MilkDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 2
    }
}

class SugarDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 1
    }
}

fun main() {
    val coffee = Coffee()
    println("Plain Coffee: ${coffee.cost()}")

    val coffeeWithMilk = MilkDecorator(coffee)
    println("Coffee with Milk: ${coffeeWithMilk.cost()}")

    val coffeeWithSugar = SugarDecorator(coffee)
    println("Coffee with Sugar: ${coffeeWithSugar.cost()}")

    val coffeeWithMilkAndSugar = SugarDecorator(coffeeWithMilk)
    println("Coffee with Milk and Sugar: ${coffeeWithMilkAndSugar.cost()}")
}