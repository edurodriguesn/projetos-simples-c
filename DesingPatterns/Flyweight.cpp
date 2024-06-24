#include <iostream>
#include <memory>
#include <unordered_map>

// Interface Flyweight
class Flyweight {
public:
    virtual void operation() const = 0;
};

// ConcreteFlyweight
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsic_state_;

public:
    ConcreteFlyweight(const std::string& intrinsic_state) : intrinsic_state_(intrinsic_state) {}

    void operation() const override {
        std::cout << "ConcreteFlyweight: Estado intrínseco é " << intrinsic_state_ << std::endl;
    }
};

// Flyweight Factory
class FlyweightFactory {
private:
    std::unordered_map<std::string, std::shared_ptr<ConcreteFlyweight>> flyweights_;

public:
    std::shared_ptr<Flyweight> getFlyweight(const std::string& key) {
        if (flyweights_.find(key) == flyweights_.end()) {
            flyweights_[key] = std::make_shared<ConcreteFlyweight>(key);
        }
        return flyweights_[key];
    }
};

int main() {
    FlyweightFactory factory;

    // Obtemos os flyweights
    std::shared_ptr<Flyweight> flyweight1 = factory.getFlyweight("Flyweight1");
    std::shared_ptr<Flyweight> flyweight2 = factory.getFlyweight("Flyweight2");
    std::shared_ptr<Flyweight> flyweight3 = factory.getFlyweight("Flyweight1");

    // Operação em cada flyweight
    flyweight1->operation();
    flyweight2->operation();
    flyweight3->operation(); // O mesmo objeto compartilhado com flyweight1

    return 0;
}
