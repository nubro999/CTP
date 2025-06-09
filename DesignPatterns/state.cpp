#include <iostream>
using namespace std;

class Headphone; // 전방 선언

class State {
public:
    virtual ~State() = default;
    virtual void pressButton1(Headphone* context) = 0;
    virtual void pressButton2(Headphone* context) = 0;
};

// 미리 선언해두기 (전방 선언)
class OffState;
class OnState;
class PlayingState;

// Headphone 정의
class Headphone {
private:
    State* state;
public:
    Headphone(State* initialState) : state(initialState) {}
    ~Headphone() { delete state; }
    void changeState(State* newState) {
        delete state;
        state = newState;
    }
    void pressButton1() { state->pressButton1(this); }
    void pressButton2() { state->pressButton2(this); }
};

// State 구현
class OffState : public State {
public:
    void pressButton1(Headphone* context) override;
    void pressButton2(Headphone* context) override {
        cout << "Headphone is off, Can't play music" << endl;
    }
};

class OnState : public State {
public:
    void pressButton1(Headphone* context) override;
    void pressButton2(Headphone* context) override;
};

class PlayingState : public State {
public:
    void pressButton1(Headphone* context) override;
    void pressButton2(Headphone* context) override;
};

// 함수 구현 분리(순환 참조 방지)
void OffState::pressButton1(Headphone* context) {
    cout << "Turning on the headphone." << endl;
    context->changeState(new OnState());
}

void OnState::pressButton1(Headphone* context) {
    cout << "Turning off the headphone." << endl;
    context->changeState(new OffState());
}
void OnState::pressButton2(Headphone* context) {
    cout << "Playing music." << endl;
    context->changeState(new PlayingState());
}

void PlayingState::pressButton1(Headphone* context) {
    cout << "Turning off the headphone." << endl;
    context->changeState(new OffState());
}
void PlayingState::pressButton2(Headphone* context) {
    cout << "Pausing music." << endl;
    context->changeState(new OnState());
}

int main() {
    Headphone headphone(new OffState());

    headphone.pressButton1(); // Turning on the headphone.
    headphone.pressButton2(); // Playing music.
    headphone.pressButton2(); // Pausing music.
    headphone.pressButton1(); // Turning off the headphone.
    headphone.pressButton2(); // Headphone is off, Can't play music
    getchar(); // Wait for user input before exiting

    return 0;
}