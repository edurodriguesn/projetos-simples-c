#include <iostream>
#include <memory>

// Interface do objeto real e do proxy
class Subject {
public:
    virtual void request() const = 0;
};

// Objeto real
class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Solicitação\n";
    }
};

// Proxy
class Proxy : public Subject {
private:
    std::shared_ptr<RealSubject> real_subject_;

public:
    Proxy(std::shared_ptr<RealSubject> real_subject) : real_subject_(real_subject) {}

    void request() const override {
        // Antes de passar a chamada para o objeto real, o proxy pode executar ações adicionais
        std::cout << "Proxy: Verificando o acesso antes de encaminhar a solicitação.\n";
        real_subject_->request();
    }
};

int main() {
    // Criando o objeto real
    auto real_subject = std::make_shared<RealSubject>();

    // Criando o proxy e passando o objeto real para ele
    Proxy proxy(real_subject);

    // Usando o proxy para fazer a chamada
    proxy.request();

    return 0;
}
