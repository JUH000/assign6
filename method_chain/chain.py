class Calculator:
    def __init__(self):
        self.result = 0
    
    def add(self, value):
        self.result += value
        return self  # 자기 자신을 반환
    
    def subtract(self, value):
        self.result -= value
        return self  # 자기 자신을 반환
    
    def multiply(self, value):
        self.result *= value
        return self  # 자기 자신을 반환
    
    def divide(self, value):
        if value != 0:
            self.result /= value
        return self  # 자기 자신을 반환
    
    def get_result(self):
        return self.result

calc = Calculator()
result = calc.add(5)\
             .multiply(2)\
             .subtract(3)\
             .divide(2)\
             .get_result()
print(result)

class PersonBuilder:
    def __init__(self):
        self.person = Person()
    
    def with_name(self, name):
        self.person.name = name
        return self  # 자기 자신을 반환
    
    def with_age(self, age):
        self.person.age = age
        return self  # 자기 자신을 반환
    
    def with_address(self, address):
        self.person.address = address
        return self  # 자기 자신을 반환
    
    def build(self):
        return self.person

class Person:
    def __init__(self):
        self.name = None
        self.age = None
        self.address = None
    
person = PersonBuilder()\
    .with_name("홍길동")\
    .with_age(20)\
    .with_address("양산시 부산대학로")\
    .build()
