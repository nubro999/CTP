#ifdef _WIN32
#include <windows.h>
#include "StateMachine.h"
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    StateMachine stateMachine;

	stateMachine.run();

	return 0;
}



