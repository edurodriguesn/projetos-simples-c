#include <iostream>
#include <memory>

// Handler base
class Handler {
protected:
    std::shared_ptr<Handler> successor;

public:
    virtual void handleRequest(int request) = 0;

    void setSuccessor(std::shared_ptr<Handler> successor) {
        this->successor = successor;
    }
};

// Concrete Handlers
class ConcreteHandler1 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 0 && request < 10) {
            std::cout << "ConcreteHandler1 handled request " << request << std::endl;
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 10 && request < 20) {
            std::cout << "ConcreteHandler2 handled request " << request << std::endl;
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
};

class ConcreteHandler3 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 20 && request < 30) {
            std::cout << "ConcreteHandler3 handled request " << request << std::endl;
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
};

int main() {
    // Criando os handlers
    auto handler1 = std::make_shared<ConcreteHandler1>();
    auto handler2 = std::make_shared<ConcreteHandler2>();
    auto handler3 = std::make_shared<ConcreteHandler3>();

    // Configurando a cadeia
    handler1->setSuccessor(handler2);
    handler2->setSuccessor(handler3);

    // Fazendo requisições
    handler1->handleRequest(5);
    handler1->handleRequest(15);
    handler1->handleRequest(25);

    return 0;
}
