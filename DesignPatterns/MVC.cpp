#include <iostream>
#include <windows.h> // For SetConsoleOutputCP

// Model : 데이터, 비즈니스 로직을 담당
class CounterModel {
private:
    int count;
public:
    CounterModel() : count(0) {}
    int getCount() const { return count; }
    void increment() { count++; }
};

// View
class CounterView {
public:
    void showCount(int count) {
        std::cout << "현재 값: " << count << std::endl;
    }
};

// Controller
class CounterController {
private:
    CounterModel& model;
    CounterView& view;
public:
    CounterController(CounterModel& m, CounterView& v) : model(m), view(v) {}

    void incrementCounter() {
        model.increment();
        view.showCount(model.getCount());
    }

    void showCounter() {
        view.showCount(model.getCount());
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8); 
    CounterModel model;
    CounterView view;
    CounterController controller(model, view);

    controller.showCounter();       // 현재 값: 0
    controller.incrementCounter();  // 현재 값: 1
    controller.incrementCounter();  // 현재 값: 2

    getchar(); // Wait for user input before closing the console window

    return 0;
}
