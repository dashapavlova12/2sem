#include <iostream>
#include <fstream>

enum err_codes
{
    BAD_ALLOC_ = -1,
    MEMORY_ERR_ = -2,
    INVALID_OP_ = -3,
    INVALID_ARG_ = -4,
    LOGIC_ERR_ = -5,
    UNKNOWN_ = -10
};

class my_exception
{
private:
    my_exception * POINTER_ = nullptr;
    int ERR_CODE_ = 0;
    int LINE_ = 0;
    const char * MESS_ = "";
    const char * FILE_ = "";
    const char * FUNC_ = "";
public:
    my_exception (const int error, const int line, const char* function,
                const char* file, const char* message, my_exception* pointer);
    friend std :: ofstream& operator << (std :: ofstream& fout, my_exception * exception);
    ~my_exception() {}
};

#define MAKE_EXCEPTION(message,code,pointer) throw new my_exception (code, __LINE__, __PRETTY_FUNCTION__, __FILE__, #message, pointer);
