class Coffee:
    def cost(self):
        return 5

class CoffeeDecorator(Coffee):
    def __init__(self, coffee):
        self._coffee = coffee
    
    def cost(self):
        return self._coffee.cost()

class MilkDecorator(CoffeeDecorator):
    def cost(self):
        return self._coffee.cost() + 2

class SugarDecorator(CoffeeDecorator):
    def cost(self):
        return self._coffee.cost() + 1

coffee = Coffee()
coffee.cost() # 5

coffee_with_milk = MilkDecorator(coffee)
coffee_with_milk.cost() # 7

coffee_with_sugar = SugarDecorator(coffee)
coffee_with_sugar.cost() # 6

coffee_with_milk_and_sugar = SugarDecorator(coffee_with_milk)
coffee_with_milk_and_sugar.cost() # 8
