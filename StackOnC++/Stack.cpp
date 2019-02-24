#include "stack.h"

Stack :: Stack()
{
    size = 2;
    capacity = INITIAL_STACK_CAPACITY;
    data = (elem_t *) calloc (capacity, sizeof(elem_t));
    data[0] = CANARY;
    data[size - 1] = CANARY;
    hash = 0;
}

Stack :: ~Stack()
{
    free (data);
    size = 0;
    capacity = 0;
    hash = 0;
}

int Stack :: StackPush (elem_t value)
{
    if (StackOk() != STACK_OK)
        return -1;
    size ++;
    if (size == capacity)
    {
        int incr = IncreaseStack();
        if (incr == -1)
            return -1;
        data[size - 2] = value;
        data[size - 1] = CANARY;
    }
    else
    {
        data[size - 2] = value;
        data[size - 1] = CANARY;
    }
    int res = HashSum();
    return res;
}

int Stack :: IncreaseStack()
{
    if (StackOk() != STACK_OK)
        return -1;
    if (data == nullptr)
        return -1;
    capacity *= 2;
    data = (elem_t *) realloc (data, capacity);
    return 0;
}

int Stack :: StackPop (elem_t * val)
{
    if (StackOk() != STACK_OK || size <= 2)
        return -1;
    hash -= data[size - 2]*(size - 2);
    * val = data[size - 2];
    data[size - 2] = POISON;
    data[size - 1] = CANARY;
    size -= 1;
    return 0;
}

int Stack :: StackDump ()
{
    if (StackOk() != STACK_OK)
    {
        printf ("Stack is broken");
        return -1;
    }
    printf ( "Stack_t \"stc\" \n");
    printf ( "capacity = %d\n", capacity);
    printf ("{\n");
    for (int i = 0; i < capacity; i++)
    {
        if (data[i] != CANARY && data[i] != POISON)
        {
            printf( "	*[%d] = %lg\n", i, data[i]);
        }
        else if (data[i] == POISON)
        {
            printf("	[%d] = %lg (POISON!)\n", i,data[i]);
        }
        else if (data[i] == CANARY)
        {
            if (i != 0)
                printf( "	*[%d] = %lg (CANARY! data doesn't belong to the stack after that value)\n", i, data[i]);
            else if (i == 0)
                printf( "	*[%d] = %lg (CANARY!)\n", i, data[i]);
        }
    }
    printf ("}\nsize = %d\n", size - 2);
    printf ("hashsum = %lg\n", hash);
    return 0;
}

int Stack :: StackOk ()
{
    if ( capacity <= 0 || data == nullptr || size < 2 || data[0] != CANARY)
    {
        return -1;
    }
    else
    {
        return STACK_OK;
    }
}

int Stack :: HashSum ()
{
    if (StackOk() != STACK_OK || size == 2)
        return -1;
    if (hash != 0)
    {
        hash += data[size - 2]*(size - 2);
        return 0;
    }
    else
    {
        for (int i = 1; i < size - 1; i++)
        {
            hash += data[i] * i;
        }
    }
    return 0;
}
