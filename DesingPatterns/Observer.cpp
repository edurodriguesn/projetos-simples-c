#include <iostream>
#include <vector>

// Observer
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// Subject
class Subject {
private:
    std::vector<Observer*> observers;
    std::string state;

public:
    // Adiciona um observador à lista
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    // Remove um observador da lista
    void removeObserver(Observer* observer) {
        // Remova o observer da lista, se presente
        //observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Notifica todos os observadores sobre uma mudança no estado
    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(state);
        }
    }

    // Define o estado e notifica observadores sobre a mudança
    void setState(const std::string& newState) {
        state = newState;
        notifyObservers();
    }
};

// ConcreteObserver
class ConcreteObserver : public Observer {
private:
    Subject* subject;

public:
    ConcreteObserver(Subject* subj) : subject(subj) {
        // Adiciona este observador à lista de observadores do Subject
        subject->addObserver(this);
    }

    // Implementação da atualização quando notificado sobre uma mudança
    void update(const std::string& message) override {
        std::cout << "Observador recebeu a mensagem: " << message << std::endl;
    }
};

int main() {
    // Criação de um Subject e dois ConcreteObservers
    Subject subject;
    ConcreteObserver observer1(&subject);
    ConcreteObserver observer2(&subject);

    // Modifica o estado do Subject, notificando os observadores
    subject.setState("Novo estado!");

    // Remoção de observer1 para que ele não receba mais notificações
    subject.removeObserver(&observer1);

    // Modifica o estado novamente, observando que observer1 não será notificado
    subject.setState("Outro estado!");

    return 0;
}

