#include <iostream>
#include <string>

using namespace std;

// State 
typedef enum {
    STATE_READY,
    STATE_NUMBER_INSERTED,
    STATE_OPERATOR_INSERTED,
    STATE_END
} State;

// Event 
typedef enum {
    EVENT_INSERT_NUMBER,
    EVENT_INSERT_OPERATOR,
    EVENT_EQUATION,
    EVENT_ERASE_ALL,
    EVENT_QUIT
} Event;

#define MAX_NUMBER_OF_ACTIONS   3       // transition 시 실행되는 최대 action 갯수

// StateMachine 클래스 정의
class StateMachine
{
private:
    State curState;     // 현재 상태

    // event-action table structure 정의
    typedef struct {
        State curState;             // 현재 상태
        Event event;                // 사용자로부터 발생된 이벤트
        int number_of_actions;                                      // 해당 transition에 실행되는 action 함수의 갯수
        void (StateMachine::*action[MAX_NUMBER_OF_ACTIONS])(int);   // action 함수 포인터의 배열
        int action_parameter[MAX_NUMBER_OF_ACTIONS];                // action 함수의 매개변수 배열
        State nextState;            // transition 후에 변경될 다음 상태
    } EventActionTable;

    // 실제 사용되는 테이블 엔트리 개수
    static const int NUMBER_OF_TABLE_ENTRIES = 9;

    // vending machine에서 사용할 event-action table 초기화
    EventActionTable table[NUMBER_OF_TABLE_ENTRIES] = {
        {STATE_READY,            EVENT_INSERT_NUMBER,    1,  {&StateMachine::displayInputValue, nullptr, nullptr},         {100, 0, 0},     STATE_NUMBER_INSERTED},
        {STATE_NUMBER_INSERTED,  EVENT_INSERT_NUMBER,    1,  {&StateMachine::displayInputValue, nullptr, nullptr},         {200, 0, 0},     STATE_NUMBER_INSERTED},
        {STATE_NUMBER_INSERTED,  EVENT_INSERT_OPERATOR,  1,  {&StateMachine::overwriteOperator, nullptr, nullptr},         {1, 0, 0},       STATE_OPERATOR_INSERTED},
        {STATE_OPERATOR_INSERTED,EVENT_INSERT_OPERATOR,  1,  {&StateMachine::overwriteOperator, nullptr, nullptr},         {2, 0, 0},       STATE_OPERATOR_INSERTED},
        {STATE_OPERATOR_INSERTED,EVENT_INSERT_NUMBER,    1,  {&StateMachine::displayInputValue, nullptr, nullptr},         {300, 0, 0},     STATE_NUMBER_INSERTED},
        {STATE_NUMBER_INSERTED,  EVENT_EQUATION,         1,  {&StateMachine::displayResult, nullptr, nullptr},             {999, 0, 0},     STATE_READY},
        {STATE_NUMBER_INSERTED,  EVENT_ERASE_ALL,        1,  {&StateMachine::eraseAllDisplayDigitWrapper, nullptr, nullptr},{0, 0, 0},      STATE_READY},
        {STATE_OPERATOR_INSERTED,EVENT_ERASE_ALL,        1,  {&StateMachine::eraseAllDisplayDigitWrapper, nullptr, nullptr},{0, 0, 0},      STATE_READY},
        {STATE_READY,            EVENT_QUIT,             1,  {&StateMachine::eraseAllDisplayDigitWrapper, nullptr, nullptr},{0, 0, 0},      STATE_END}
    };

    void displayInputValue(int displayedValue); // LED 화면에 현재 투입된 금액을 표시함
    void overwriteOperator(int op);             // 연산자 입력을 처리함
    void displayResult(int result);             // 결과 표시
    void eraseAllDisplayDigit();                // 화면 지움

    // 파라미터 없는 함수를 위한 wrapper
    void eraseAllDisplayDigitWrapper(int) { eraseAllDisplayDigit(); }

    Event getNextEvent();       // 사용자로부터 다음 이벤트를 입력받음
    string getCurrentStateString();     // 현재 상태 문자열 반환

public:
    void run();               // state machine 실행 
};