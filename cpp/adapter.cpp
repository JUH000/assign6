#include <iostream>
#include <string>

// 내부 클래스 (클라이언트가 기대하는 인터페이스)
class InternalClass {
public:
    virtual std::string fetch() const = 0;
    virtual ~InternalClass() = default;
};

// 외부 클래스 (인터페이스가 다름)
class ExternalClass {
public:
    std::string search() const {
        return "get user info";
    }
};

// 어댑터 클래스 (ExternalClass → InternalClass 형태로 어댑팅)
class Adapter : public InternalClass {
private:
    ExternalClass* external;
public:
    Adapter(ExternalClass* ext) : external(ext) {}

    std::string fetch() const override {
        return external->search();
    }
};

int main() {
    ExternalClass external;
    Adapter adapter(&external);

    std::cout << adapter.fetch() << std::endl;  // "get user info"
    return 0;
}
