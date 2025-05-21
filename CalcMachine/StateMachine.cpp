#include <string>
#include "StateMachine.h"

void StateMachine::run()
{
    int i, j;
    Event curEvent;

    curState = STATE_READY;
    while (curState != STATE_END)
    {
        curEvent = getNextEvent();

        bool matched = false;
        for (i = 0; i < NUMBER_OF_TABLE_ENTRIES; i++)
        {
            if (curState == table[i].curState && curEvent == table[i].event)
            {
                for (j = 0; j < table[i].number_of_actions; j++)
                {
                    if (table[i].action[j])
                        (this->*table[i].action[j])(table[i].action_parameter[j]);
                }
                curState = table[i].nextState;
                matched = true;
                break;
            }
        }
        if (!matched)
            cout << "잘못된 방식" << endl;
        cout << endl << endl;
    }
}

Event StateMachine::getNextEvent()
{
    Event selectedEvent;
    int inputEvent;

    cout << "[현재 상태 : " << getCurrentStateString() << "]" << endl;
    cout << "1. 숫자를 입력" << endl;
    cout << "2. 연산자를 입력" << endl;
    cout << "3. = 입력" << endl;
    cout << "4. 화면지우기" << endl;
    cout << "5. 종료" << endl;
    cout << "Select an event # : ";

    cin >> inputEvent;

    switch (inputEvent)
    {
    case 1:
        selectedEvent = EVENT_INSERT_NUMBER;
        break;
    case 2:
        selectedEvent = EVENT_INSERT_OPERATOR;
        break;
    case 3:
        selectedEvent = EVENT_EQUATION;
        break;
    case 4:
        selectedEvent = EVENT_ERASE_ALL;
        break;
    case 5:
        selectedEvent = EVENT_QUIT;
        break;
    default:
        selectedEvent = EVENT_QUIT;
    }

    return selectedEvent;
}

void StateMachine::displayInputValue(int displayedValue)
{
    cout << "현재 입력된 수식은 " << displayedValue << "입니다." << endl;
}

void StateMachine::overwriteOperator(int op)
{
    cout << "현재 입력된 연산자는 " << op << "입니다." << endl;
}

void StateMachine::displayResult(int result)
{
    cout << "현재 계산된 결과는 " << result << "입니다." << endl;
}

void StateMachine::eraseAllDisplayDigit()
{
    cout << "화면 초기화" << endl;
}

string StateMachine::getCurrentStateString()
{
    switch (curState)
    {
    case STATE_READY:
        return "STATE_READY";
    case STATE_NUMBER_INSERTED:
        return "STATE_NUMBER_INSERTED";
    case STATE_OPERATOR_INSERTED:
        return "STATE_OPERATOR_INSERTED";
    case STATE_END:
        return "STATE_END";
    default:
        return "UNKNOWN_STATE";
    }
}