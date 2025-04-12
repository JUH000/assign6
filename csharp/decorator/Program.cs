using System;

class Coffee {
    public virtual int Cost() {
        return 5;
    }
}

class CoffeeDecorator : Coffee {
    protected Coffee coffee;

    public CoffeeDecorator(Coffee coffee) {
        this.coffee = coffee;
    }

    public override int Cost() {
        return coffee.Cost();
    }
}

class MilkDecorator : CoffeeDecorator {
    public MilkDecorator(Coffee coffee) : base(coffee) {}

    public override int Cost() {
        return coffee.Cost() + 2;
    }
}

class SugarDecorator : CoffeeDecorator {
    public SugarDecorator(Coffee coffee) : base(coffee) {}

    public override int Cost() {
        return coffee.Cost() + 1;
    }
}

class Program {
    static void Main(string[] args) {
        Coffee coffee = new Coffee();
        Console.WriteLine("Plain Coffee: " + coffee.Cost());

        Coffee coffeeWithMilk = new MilkDecorator(coffee);
        Console.WriteLine("Coffee with Milk: " + coffeeWithMilk.Cost());

        Coffee coffeeWithSugar = new SugarDecorator(coffee);
        Console.WriteLine("Coffee with Sugar: " + coffeeWithSugar.Cost());

        Coffee coffeeWithMilkAndSugar = new SugarDecorator(coffeeWithMilk);
        Console.WriteLine("Coffee with Milk and Sugar: " + coffeeWithMilkAndSugar.Cost());
    }
}