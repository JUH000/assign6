#include <iostream>
#include <memory>

class Coffee {
public:
    virtual int cost() const {
        return 5;
    }
    virtual ~Coffee() = default;
};

class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> coffee;
public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : coffee(coffee) {}
    int cost() const override {
        return coffee->cost();
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 2;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 1;
    }
};

int main() {
    auto coffee = std::make_shared<Coffee>();
    std::cout << "Plain Coffee: " << coffee->cost() << "\n";

    auto coffeeWithMilk = std::make_shared<MilkDecorator>(coffee);
    std::cout << "Coffee with Milk: " << coffeeWithMilk->cost() << "\n";

    auto coffeeWithSugar = std::make_shared<SugarDecorator>(coffee);
    std::cout << "Coffee with Sugar: " << coffeeWithSugar->cost() << "\n";

    auto coffeeWithMilkAndSugar = std::make_shared<SugarDecorator>(coffeeWithMilk);
    std::cout << "Coffee with Milk and Sugar: " << coffeeWithMilkAndSugar->cost() << "\n";

    return 0;
}