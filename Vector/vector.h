#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define NEW new(__FILE__,__func__,__LINE__)
#define DELETE(point)                                                               \
{                                                                                   \
    PRINT_LOGS_MEM ("%8d freed     %s %s %d", point, __FILE__, __func__, __LINE__); \
    delete point;                                                                   \
}

#define PRINT_LOGS_VTR(s, ...) \
    fprintf(log_file_vector, "%s # " s "\n", __TIME__, ##__VA_ARGS__)
#define PRINT_LOGS_MEM(s, ...) \
    fprintf(log_file_memory, "%s # " s "\n", __TIME__, ##__VA_ARGS__)

const char *log_file_vector_name = "vector_log.txt";
const char *log_file_memory_name = "memory_log.txt";

FILE *log_file_vector = fopen (log_file_vector_name, "w");
FILE *log_file_memory = fopen (log_file_memory_name, "w");

int SIZE_DESTRUCT = -1;

template <typename data_t>
class vector{
private:
    data_t * data;
    data_t poison;
    size_t size;
public:
    explicit vector ();
    vector (const vector & that);
    vector (vector && that);
    vector (size_t size);
    ~vector ();

    int swap (vector & that);
    int clear (data_t content = 0);
    int resize (size_t count);
    const data_t &at (size_t index) const;
    const vector &operator= (vector && that);
    const vector &operator= (const vector & that);
    data_t &operator[] (size_t index);
    const size_t size_ () const;
};


template <typename data_t>
std :: istream &operator>> (std :: istream & in, const vector <data_t> & lhs);

template <typename data_t>
std :: ostream &operator<< (std :: ostream & out, const vector <data_t> & lhs);

template <typename data_t>
int operator== (const vector<data_t> & lhs, const vector<data_t> & rhs);

template <typename data_t>
int operator!= (const vector<data_t> & lhs, const vector<data_t> & rhs);

template <typename data_t>
vector<data_t> operator+ (const vector<data_t> & lhs, const vector<data_t> & rhs);

template <typename data_t>
vector<data_t> operator+ (const vector<data_t> & lhs, const data_t & num);

template <typename data_t>
vector<data_t> operator+ (const data_t &num,const vector<data_t> & rhs);

template <typename data_t>
vector<data_t> operator* (const vector<data_t> & lhs, const data_t & num);

template <typename data_t>
vector<data_t> operator* (const data_t &num,const vector<data_t> & rhs);

template <typename data_t>
vector<data_t> operator- (const vector<data_t> & lhs, const vector<data_t> & rhs);

template <typename data_t>
vector<data_t> operator- (const vector<data_t> & lhs, const data_t & num);

template <typename data_t>
vector<data_t> operator- (const data_t &num,const vector<data_t> & rhs);

template <typename data_t>
vector<data_t> operator/ (const vector<data_t>& lhs, const data_t& num);

void * operator new (size_t size, const char * file, const char * fun, int line);

void * operator new[] (size_t size, const char * file, const char * fun, int line);

void operator delete (void * p) noexcept;

void operator delete[] (void * p) noexcept;
