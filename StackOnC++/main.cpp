#include "stack.h"

int main()
{
   Stack Values = Stack();
   int res = Values.StackPush(10);
   res = Values.StackPush(-5);
   res = Values.StackPush(123);
   res = Values.StackDump();
}
