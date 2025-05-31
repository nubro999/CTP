#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    // Private constructor to prevent instantiation

    Singleton() {
        cout << "Singleton instance created." << endl;
    }
public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static method to get the instance of the singleton
    static Singleton* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
    
    void showMessage() {
        cout << "Hello from the Singleton!" << endl;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    // Get the singleton instance and call a method
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();

    // Attempt to get another instance
    Singleton* anotherSingleton = Singleton::getInstance();
    anotherSingleton->showMessage();

    // Check if both instances are the same
    if (singleton == anotherSingleton) {
        cout << "Both instances are the same." << endl;
    } else {
        cout << "Instances are different." << endl;
    }

    getchar(); // Wait for user input before exiting
    return 0;
}