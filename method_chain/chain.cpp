#include <iostream>
#include <string>
#include <memory>

class Person {
public:
    std::string name;
    int age;
    std::string address;
};

class PersonBuilder {
private:
    std::unique_ptr<Person> person;
public:
    PersonBuilder() : person(std::make_unique<Person>()) {}

    PersonBuilder& withName(const std::string& name) {
        person->name = name;
        return *this;
    }

    PersonBuilder& withAge(int age) {
        person->age = age;
        return *this;
    }

    PersonBuilder& withAddress(const std::string& address) {
        person->address = address;
        return *this;
    }

    std::unique_ptr<Person> build() {
        return std::move(person);
    }
};

int main() {
    auto person = PersonBuilder()
        .withName("홍길동")
        .withAge(20)
        .withAddress("양산시 부산대학로")
        .build();

    std::cout << "Name: " << person->name << "\n";
    std::cout << "Age: " << person->age << "\n";
    std::cout << "Address: " << person->address << "\n";

    return 0;
}