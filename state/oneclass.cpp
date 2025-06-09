#include <stdio.h>
using namespace std;

class StateMachine
 {

 private:
 void action(int para) {
 printf("action executed : % d !\n", para);
 };


 void (StateMachine::*fptr)(int) = &StateMachine::action; // Function pointer to member function     

public:
 void testFptr(int para) {
 (this->*fptr)(para);                   
    printf("testFptr executed : % d !\n", para);
 };
 };


 int main()
 {
 StateMachine statemachine;
 statemachine.testFptr(4);
 getchar(); // Wait for user input before exiting
 return 0;
 }