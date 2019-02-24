#include <iostream>
#include <cstdlib>

typedef double elem_t;

const int INITIAL_STACK_CAPACITY = 10;
const elem_t CANARY = 666.666;
const elem_t POISON = -666;
const int STACK_OK = 0;

class Stack{
public:
    Stack();
    ~Stack();
    int StackPush(elem_t value);
    int StackPop (elem_t * val);
    int StackDump ();
    int StackOk ();
    int IncreaseStack ();
    int HashSum ();
private:
    elem_t * data;
    int size;
    int capacity;
    elem_t hash;
};
