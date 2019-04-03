#include "myexception.h"

my_exception :: my_exception (const int error, const int line, const char* function,
              const char* file, const char* message, my_exception* pointer)
{
    ERR_CODE_ = error;
    LINE_ = line;
    MESS_ = message;
    FUNC_ = function;
    FILE_ = file;
    POINTER_ = pointer;
}

std :: ofstream& operator << (std :: ofstream& fout, my_exception * exception)
{
    while (exception != nullptr)
    {
        fout << "ERROR! " << exception -> MESS_ << std :: endl;
        fout << "File: " << exception -> FILE_ << std :: endl;
        fout << "Function: " << exception -> FUNC_ << std :: endl;
        fout << "Line: " << exception -> LINE_ << std :: endl;
        fout << "Code: " << exception -> ERR_CODE_ << std :: endl;

        if (exception -> POINTER_ != nullptr)
            fout << "...." << std :: endl;

        exception = exception -> POINTER_;
    }
    return fout;
}

