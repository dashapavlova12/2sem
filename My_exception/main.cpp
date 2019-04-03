#include "myexception.h"

std :: ofstream log_file ("Log.txt");

void test_func1 ();
void test_func2 ();

int main ()
{
    try
    {
        test_func1 ();
    }
    catch (my_exception* exception)
    {
        log_file << exception;
    }
}

void test_func1 ()
{
    try
    {
        test_func2();
    }
    catch (my_exception * exception)
    {
        if (true)
            MAKE_EXCEPTION(Memory error,MEMORY_ERR_,exception);
    }
}

void test_func2 ()
{
    if (true)
        MAKE_EXCEPTION(Logic error,LOGIC_ERR_,nullptr);
}
