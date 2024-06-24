#include <iostream>

class Singleton {
    private:
        static Singleton* instance;
        Singleton() {}
    
    public:
        static Singleton* getInstance() {
            if (!instance) {
                instance = new Singleton();
            }
            return instance;
        }
    
        void showMessage() {
            std::cout << "Mensagem do Singleton\n";
        }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singletonInstance1 = Singleton::getInstance();
    singletonInstance1->showMessage();

   // Singleton* singletonInstance2 = new Singleton(); 

    return 0;
}
